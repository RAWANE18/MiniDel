%{
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
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
  int j ,l;
  bool logic =false;
char cst[20];
char cst2[20];
char svcst2[20];
char svop[20];
char svtaille[20];
int Fin_else=0,deb_else=0,deb_while=0 ,cond1=0,cond2=0;
char tmp [20]; 

%}
%union {
    char *str; 
} 
/*----------------------- Définition des mots clé et opérends----------------------------*/
%token mc_PROGRAM mc_VAR mc_begin mc_END <str>mc_CONST <str>mc_INTEGER <str>mc_FLOAT mc_IF mc_ELSE mc_FOR mc_WHILE mc_READLN mc_WRITELN 
%token <str>op_ADD <str>op_SUB <str>op_MUL <str>op_DIV op_AND op_OR op_NOT op_EQ op_NEG op_INF op_INF_E op_SUP op_SUP_E op_AFF PO PF OB FB ALO ALF VIR PVIR DPOINT 
%token <str>IDF ERR STR <str>REEL <str>INT 
%type <str> expression term expC 
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


instWHILE: WW ALO corps ALF
           {
            sprintf(tmp,"%d",deb_while); 
            quadr("BR",tmp,"vide", "vide");
				   sprintf(tmp,"%d",qc); 
            ajour_quad(deb_while,1,tmp);}
;
WW: mc_WHILE PO expC PF
 {deb_while=qc;
quadC(j,"","", "");
ajour_quad(deb_while,2,cst);
ajour_quad(deb_while,3,cst2);
}

instIF :Belse mc_ELSE ALO corps ALF  { 
     sprintf(tmp,"%d",qc);  
     ajour_quad(Fin_else,1,tmp);}
       |B
;
Belse : N ALO corps ALF   {  
				   Fin_else=qc;
           quadr("BR","","vide", "vide"); 
				   sprintf(tmp,"%d",qc); 
           ajour_quad(cond2,1,tmp);
          if(l==2)ajour_quad(cond1,1,tmp);	///le cas de && on sort si la premiere false

				   }
;  

B: N ALO corps ALF { 
				   sprintf(tmp,"%d",qc); 
           ajour_quad(cond2,1,tmp);	
           if(l==2){ajour_quad(cond1,1,tmp);}	///le cas de && on sort si la premiere false
}
;
N : F | A ; // SOIT AVEC OP LOGIQUE  SOIT OP SIMPLE

F : E expC PF {
   cond2=qc; 
   if(l==3){logic=true;}
   else{logic=false;} // dans le tous les cas la deuxieme cond ne change pas 
  quadL(l,j,"","","",logic);
  sprintf(tmp,"%d",qc); 
  ajour_quad(cond1,1,tmp);
  ajour_quad(cond2,2,cst);
  ajour_quad(cond2,3,cst2);
 
}
;
E :  mc_IF PO expC op_logique
 { cond1=qc;
 quadL(l,j,"","","",logic);
ajour_quad(cond1,2,cst);
ajour_quad(cond1,3,cst2);}
|mc_IF PO op_NOT {l=3;} //logic pour le cas du OR de la premiere cond
;
A: mc_IF PO expC  PF {
deb_else=qc;
quadC(j,"","", "");
ajour_quad(deb_else,2,cst);
ajour_quad(deb_else,3,cst2);
}
;

op_logique : op_AND  {l=2;}
| op_OR  {l=1;logic=true; } //les indices pour gerer les BL, BG dans le cas du premiere condition
;


expC : expC op_SUP expC {
             j=1;
            strcpy(cst,$1);
            strcpy(cst2,$3); 
        }
     | expC op_SUP_E expC {
            j=2;
            strcpy(cst,$1);
            strcpy(cst2,$3); 
        }
     | expC op_INF expC{
              j=3;
            strcpy(cst,$1);
            strcpy(cst2,$3); 
        }
     | expC op_INF_E expC {
             j=4;
            strcpy(cst,$1);
            strcpy(cst2,$3);   
        }
     | expC op_EQ expC {
            j=5;
            strcpy(cst,$1);
            strcpy(cst2,$3);  
        }
     | expC op_NEG expC {
            j=6;
            strcpy(cst,$1);
            strcpy(cst2,$3);         }
     | expression {
            $$ = $1; 
        } 
        | PO expression PF {
            $$ = $2; 
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
          | IDF OB INT FB op_AFF expression {  
            if(declarer($1)!=1){ printf("erreur Semantique: Variable Non declaree (inconnue) : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);YYABORT;}
           if(div_zero($6,svop)!=0){printf("erreur Semantique: Division par '0' a la ligne %d a la colonne %d\n", nb_ligne,Col);YYABORT;} 
           if(verefier_cst($1)==1){printf("erreur Semantique: changement de valeur de constante a la ligne %d a la colonne %d\n", nb_ligne,Col);YYABORT;}
         quadr("=", $6, "", $1); if(strtol($3, NULL, 10) > strtol(svtaille, NULL, 10)){printf("erreur Semantique: depassement de taille:%s a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);YYABORT;}
          if(areTypesCompatible($1,$6)==1){
             printf("Warning: conversion implicite vers un type superieur : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
        }if(areTypesCompatible($1,$6)==-1){
             printf("erreur Semantique: Type non compatyble : %s, a la ligne %d a la colonne %d\n",$1, nb_ligne,Col);
             
        } }

          ;

expression
    : term          { $$ = $1; strcpy(svcst,$1);}
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




operation : op_SUB { $$ = "-"; }
    | op_ADD { $$ = "+"; }
    | op_DIV { $$ = "/"; strcpy(svop,$1); } 
    |op_MUL { $$ = "*"; }                
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