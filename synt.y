%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ts.h"
void yyerror(const char *s);
extern char *yytext;
int yylex();
int nb_ligne=1;
int Col=1;
char tempval[20];
char svtype[20];
char svcst[20];
char svop[20];
char svtaille[20];
%}
%union {
    char *str; 
} 
/*----------------------- Définition des mots clé et opérends----------------------------*/
%token mc_PROGRAM mc_VAR mc_begin mc_END <str>mc_CONST <str>mc_INTEGER <str>mc_FLOAT mc_IF mc_ELSE mc_FOR mc_WHILE mc_READLN mc_WRITELN
%token <str>op_ADD <str>op_SUB <str>op_MUL <str>op_DIV op_AND op_OR op_NOT op_EQ op_NEG op_INF op_INF_E op_SUP op_SUP_E op_AFF PO PF OB FB ALO ALF VIR PVIR DPOINT 
%token <str>IDF ERR STR <str>REEL <str>INT 

/*----------------------- Les Priorités ----------------------------*/
%nonassoc op_NOT
%left op_OR
%left op_AND

%left op_SUP op_SUP_E op_EQ op_NEG op_INF_E op_INF

%left op_ADD op_SUB
%left op_MUL op_DIV

%start S
%%
/*----------------------- Syntax générale du Programme ----------------------------*/

S: mc_PROGRAM IDF mc_VAR ALO declarationV ALF mc_begin corps mc_END  
{    printf("\t ___________________________________\n");
printf("\t |Programme syntaxiquement correcte| \n");    printf("\t |_________________________________|\n");
 YYACCEPT;}
;
/*----------------------- Structure de déclaration des variables ----------------------------*/
declarationV : type listeV PVIR declarationV
             | type listeT PVIR declarationV 
	      | mc_CONST listeC PVIR declarationV 
	      | type listeV PVIR 
	      | mc_CONST listeC PVIR
	      | type listeT PVIR
;
type : mc_INTEGER {strcpy(svtype,$1);}
     | mc_FLOAT {strcpy(svtype,$1);}
;
ARRAY : IDF OB taille FB {if(declarer($1)!=1){ int idx; idx=rechercher($1, "Identificateur", "Tableau","", 0);}else{yyerror("declared");YYABORT; }}
;
taille:INT {strcpy(svtaille,$1);}
;
listeT : ARRAY VIR listeT 
       | ARRAY 
;
listeC :  IDF op_AFF val VIR listeC {if(declarer($1)!=1){int idx; idx=rechercher($1, "Identificateur", "CONSTANTE", tempval, 0);}else{yyerror("declared");YYABORT; }}
       |  IDF op_AFF val {if(declarer($1)!=1){int idx; idx=rechercher($1, "Identificateur", "CONSTANTE", tempval, 0);}else{yyerror("declared");YYABORT; }}
;
val:INT {strcpy(tempval,$1);}
   |REEL {strcpy(tempval,$1);}
;
listeV : IDF VIR listeV {if(declarer($1)!=1){ yyerror("declared");YYABORT;}}
       | IDF op_AFF val VIR listeV {if(declarer($1)!=1){int idx; idx=rechercher($1, "Identificateur", svtype, tempval, 0);}else{yyerror("declared");YYABORT; }}
       | IDF {if(declarer($1)!=1){ yyerror("declared");YYABORT;}}
       | IDF op_AFF val {if(declarer($1)!=1){int idx; idx=rechercher($1, "Identificateur",svtype, tempval, 0);}else{yyerror("declared");YYABORT; }}
;
/*----------------------- Structure du corps de programme ----------------------------*/
corps : corps instruction 
      | instruction 
;
instruction : instAFF PVIR
            | instIF
            | instWHILE
            | instFOR
            | instREADLN PVIR
            | instWRITELN PVIR
;
instAFF :IDF OB INT FB op_AFF expression {if(strtol($3, NULL, 10) > strtol(svtaille, NULL, 10)){printf("erreur Semantique: depassement de taille:%s a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);YYABORT;}}
        |IDF op_AFF expression {if(declarer($1)!=1){ 
        printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
        YYABORT;}
        if(div_zero(svcst,svop)!=0){
printf("erreur Semantique: Division par '0' a la ligne %d a la colonne %d\n", nb_ligne,Col);
        YYABORT;
        }
        }
;
instIF : mc_IF PO cond PF ALO corps ALF 
       | mc_IF PO cond PF ALO corps ALF mc_ELSE ALO corps ALF
;
instWHILE : mc_WHILE PO cond PF ALO corps ALF 
;
instFOR : mc_FOR PO IDF DPOINT INT DPOINT INT DPOINT IDF PF ALO corps ALF {if(declarer($3)!=1){  
       printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
       YYABORT;}
       else if(declarer($9)!=1){
              printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$9, nb_ligne,Col);
              YYABORT;}}
;
instREADLN : mc_READLN PO IDF PF {if(declarer($3)!=1){
        printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$3, nb_ligne,Col);
        YYABORT;}}
;

instWRITELN : mc_WRITELN PO string PF 
;
string : string STR 
       | string IDF {if(declarer($2)!=1){ 
               printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$2, nb_ligne,Col);
               YYABORT;}}
	|STR
	|IDF {if(declarer($1)!=1){ 
               printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
               YYABORT;}}
 ;

expression : expression op_ADD expression  {strcpy(svop,$2);}
           | expression op_SUB expression  {strcpy(svop,$2);}
           | expression op_MUL expression {strcpy(svop,$2);}
           | expression op_DIV expression {strcpy(svop,$2);}
           | PO expression PF
           | IDF OB INT FB {if(strtol($3, NULL, 10) > strtol(svtaille, NULL, 10)){printf("erreur Semantique: depassement de taille a la ligne %d a la colonne %d\n", nb_ligne,Col);YYABORT;}}
           | INT {strcpy(svcst,$1);}
           | REEL{strcpy(svcst,$1);}
           | IDF {if(declarer($1)!=1){  
              printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
              YYABORT;}
              strcpy(svcst,$1);}
;
cond : expression op_EQ expression 
     | expression op_NEG expression 
     | expression op_INF expression 
     | expression op_SUP expression 
     | expression op_INF_E expression 
     | expression op_SUP_E expression 
     | PO expression PF op_AND PO expression PF
     | PO expression PF op_OR PO expression PF
     | PO op_NOT expression PF
;
%%
int main()
{yyparse();
afficher();

  return 0;
}

int yywrap()
{
return 1;
}


void yyerror(const char *s){
printf("Error: %s ligne %d colonne %d sur l'entite %s\n",s,nb_ligne, Col, yytext ? yytext :"unknown");
}
