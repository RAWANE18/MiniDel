%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ts.h"
#include "quad.h"
void yyerror(const char *s);
extern char *yytext;
int yylex();
int nb_ligne=1;
int Col=1;
char tempval[20];
char svtype[20];
char svcst[20];
char svcst2[20];
char svop[20];
char svtaille[20];
int Fin_if=0,deb_else=0;
char tmp [20]; 
int tete = -1; 
int deb_else_pile[100];

%}
%union {
    char *str; 
} 
/*----------------------- Définition des mots clé et opérends----------------------------*/
%token mc_PROGRAM mc_VAR mc_begin mc_END <str>mc_CONST <str>mc_INTEGER <str>mc_FLOAT mc_IF mc_ELSE mc_FOR mc_WHILE mc_READLN mc_WRITELN 
%token <str>op_ADD <str>op_SUB <str>op_MUL <str>op_DIV op_AND op_OR op_NOT op_EQ op_NEG op_INF op_INF_E op_SUP op_SUP_E op_AFF PO PF OB FB ALO ALF VIR PVIR DPOINT 
%token <str>IDF ERR STR <str>REEL <str>INT 
%type <str> expression term expC cond
%type <str> operation

/*----------------------- Les Priorités ----------------------------*/
%nonassoc op_NOT
%left op_OR
%left op_AND

%left op_SUP op_SUP_E op_EQ op_NEG op_INF_E op_INF

%left op_MUL op_DIV
%left op_ADD op_SUB

%start S
%%
/*----------------------- Syntax générale du Programme ----------------------------*/

S: mc_PROGRAM IDF mc_VAR ALO declarationV ALF mc_begin corps mc_END  
{ printf("\t ___________________________________\n");
printf("\t |Programme syntaxiquement correcte| \n");    printf("\t |_________________________________|\n");
 YYACCEPT;}
| mc_PROGRAM IDF mc_VAR ALO declarationV ALF mc_begin corps mc_END AFTER_END
    {
        printf("\t | Erreur: Texte supplementaire apres END ! |\n");
        YYERROR;
    };
MC:mc_PROGRAM |mc_VAR |mc_begin |mc_END |mc_CONST |mc_INTEGER |mc_FLOAT |mc_IF |mc_ELSE |mc_FOR |mc_WHILE |mc_READLN |mc_WRITELN;
AFTER_END:MC|term;
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
ARRAY : IDF OB taille FB {if(declarer($1)!=1){int idx; idx=rechercher($1,"Identificateur",svtype,"Tableau","", 0);}else{yyerror("declared");YYABORT; }}
;
taille:INT {strcpy(svtaille,$1);}
;
listeT : ARRAY VIR listeT 
       | ARRAY 
;
listeC :  AFFVALCST VIR listeC 
       |  AFFVALCST 
;
AFFVALCST: IDF op_AFF val {if(declarer($1)!=1){int idx; idx=rechercher($1, "Identificateur",svtype,"CONSTANTE", tempval, 0);}else{yyerror("declared");YYABORT; }}
;
val:INT {strcpy(tempval,$1);strcpy(svtype,"INTEGER");}
   |REEL {strcpy(tempval,$1);strcpy(svtype,"FLOAT");}
;
listeV : IDF VIR listeV {if(declarer($1)!=1){int idx; idx=rechercher($1, "Identificateur",svtype,svtype, "", 0);}else{yyerror("declared");YYABORT; }}
       | AFFVAL VIR listeV 
       | IDF {if(declarer($1)!=1){int idx; idx=rechercher($1, "Identificateur", svtype, svtype,"", 0);}else{ yyerror("declared");YYABORT;}}
       | AFFVAL;
AFFVAL : IDF op_AFF val {if(declarer($1)!=1){int pos; pos=rechercher($1, "Identificateur",svtype, svtype,tempval, 0);}else{yyerror("declared");YYABORT; }}
;
/*----------------------- Structure du corps de programme ----------------------------*/
corps : instruction corps 
      | instruction 
;
instruction : instAFF PVIR
            | instIF
            | instWHILE
            | instFOR
            | instREADLN PVIR
            | instWRITELN PVIR
;

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
string : STR string
       | IDF string{if(declarer($1)!=1){ 
               printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
               YYABORT;}}
	|STR
	|IDF {if(declarer($1)!=1){ 
               printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
               YYABORT;}}
 ;



instIF :Belse mc_ELSE ALO corps ALF  { 
     sprintf(tmp,"%d",qc);  
                              ajour_quad(Fin_if,1,tmp);}
       |B
;
Belse : A ALO corps ALF   {  
				   Fin_if=qc;
                   quadr("BR", "","vide", "vide"); 
				   sprintf(tmp,"%d",qc); 
                   ajour_quad(deb_else,1,tmp);
				   }
;    

B: A ALO corps ALF { 
    sprintf(tmp, "%d", qc); 
    ajour_quad(deb_else_pile[tete], 1, tmp); 
    tete--; 
}
;

A: mc_IF PO cond PF { 
    deb_else_pile[++tete] = qc; 
    quadr("BZ", "", $3, "");
}
;


instAFF : IDF op_AFF expression  {
           if(declarer($1)!=1){ printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);YYABORT;}
           if(div_zero(svcst,svop)!=0){printf("erreur Semantique: Division par '0' a la ligne %d a la colonne %d\n", nb_ligne,Col);YYABORT;} 
           if(verefier_cst($1)==1){printf("erreur Semantique: changement de valeur de constante a la ligne %d a la colonne %d\n", nb_ligne,Col);YYABORT;}
         if(areTypesCompatible($1,$3)==1){
             printf("Warning: conversion implicite vers un type superieur : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
        }if(areTypesCompatible($1,$3)==-1){
             printf("erreur Semantique: Type non compatyble : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
             
        } quadr("=", $3, "", $1);}
          | IDF OB INT FB op_AFF expression {quadr("=", $6, "", $1); if(strtol($3, NULL, 10) > strtol(svtaille, NULL, 10)){printf("erreur Semantique: depassement de taille:%s a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);YYABORT;}}

          ;

expression
    : term          { $$ = $1; }
    | term operation  expression 
    {
         if(areTypesCompatible($1,$3)==0){
            strcpy(svtype,$1);
        }else{
             printf("Warning: Type non compatyble : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
               strcpy(svtype,"FLOAT");
        }
          char* temp = newTempVar();
          quadr($2, $1, $3, temp); 
          $$ = temp;
          
       
        }
        | PO expression PF operation  expression 
     {
           if(areTypesCompatible($2,$5)==0){
            strcpy(svtype,$1);
        }else{
             printf("Warning: Type non compatyble : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
               strcpy(svtype,"FLOAT");
        }
          char* temp = newTempVar();
          quadr($4, $2, $5, temp);
          $$ = temp;
          
        }
      
     |term operation  PO expression PF 
     {
         if(areTypesCompatible($1,$4)==0){
            strcpy(svtype,$1);
        }else{
             printf("Warning: Type non compatyble : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
               strcpy(svtype,"FLOAT");
        }char* temp = newTempVar();
          quadr($2, $4, $1, temp);
          $$ = temp;
          }
     

;

term: IDF                      { $$ = $1;   strcpy(svcst,$1);strcpy(svtype,$1);} 
    | INT                      { $$ = $1;   strcpy(svcst,$1); strcpy(svtype,"INTEGER");}
    | REEL                     { $$ = $1;   strcpy(svcst,$1);strcpy(svtype,"FLOAT");}
    | IDF OB INT FB             { $$ = $1;   strcpy(svcst,$1);strcpy(svtype,$1);} 
;


instWHILE: E ALO corps ALF 
E: mc_WHILE  PO cond PF { quadr("BR", "", $3, "");}
 


operation : op_SUB { $$ = "-"; }
    | op_ADD { $$ = "+"; }
    | op_DIV { $$ = "/"; strcpy(svop,$1); } 
    |op_MUL { $$ = "*"; }                
;
cond : op_NOT cond {char* temp = newTempVar(); 
            quadL(1, $2,"", temp); 
            $$ = temp;}
     | cond op_AND cond 
     {
    quadr("BZ", " ", $1," ");        
    quadr("BZ", " ", $3," ");   
     char* temp = newTempVar(); 
            quadL(2, $1,$3, temp); 
            $$ = temp;     
     }
     | cond op_OR cond  {
    quadr("BZ", "", $1," ");        
    quadr("BZ", " ", $3," ");   
     char* temp = newTempVar(); 
            quadL(3, $1,$3, temp); 
            $$ = temp;     
     }
     | expC 
     ;


expC : expC op_SUP expC {
            char* temp = newTempVar(); 
            quadC(1, $1, $3, temp); 
            $$ = temp;
        }
     | expC op_SUP_E expC {
            char* temp = newTempVar(); 
            quadC(2, $1, $3, temp); 
            $$ = temp;
        }
     | expC op_INF expC {
            char* temp = newTempVar(); 
            quadC(3, $1, $3, temp); 
            $$ = temp;
        }
     | expC op_INF_E expC {
            char* temp = newTempVar(); 
            quadC(4, $1, $3, temp); 
            $$ = temp;
        }
     | expC op_EQ expC {
            char* temp = newTempVar(); 
            quadC(5, $1, $3, temp); 
            $$ = temp;
        }
     | expC op_NEG expC {
            char* temp = newTempVar(); 
            quadC(6, $1, $3, temp); 
            $$ = temp;
        }
     | expression {
            $$ = $1; 
        }
     ;


%%
int main()
{yyparse();
afficher();
afficher_qdr();
  return 0;
}

int yywrap()
{
return 1;
}


void yyerror(const char *s){
printf("Error: %s ligne %d colonne %d sur l'entite %s\n",s,nb_ligne, Col, yytext ? yytext :"unknown");
}