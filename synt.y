%{
#include <string.h>
#include <stdio.h>
#include "ts.h"
void yyerror(const char *s);
extern char *yytext;
int yylex();
int nb_ligne=1;
int Col=1;
%}
%union {
    char *str;
    int entier;
    float reel;
} 
/*----------------------- Définition des mots clé et opérend----------------------------*/
%token mc_PROGRAM mc_VAR mc_begin mc_END mc_CONST mc_INTEGER mc_FLOAT mc_IF mc_ELSE mc_FOR mc_WHILE mc_READLN mc_WRITELN
%token op_ADD op_SUB op_MUL op_DIV op_AND op_OR op_NOT op_EQ op_NEG op_INF op_INF_E op_SUP op_SUP_E op_AFF PO PF OB FB ALO ALF VIR PVIR DPOINT AP
%token IDF ERR STR 

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

S: mc_PROGRAM IDF mc_VAR ALO declarationV ALF mc_begin ALO corps ALF mc_END  
{printf("\nProgramme syntaxiquement correcte. \n"); YYACCEPT;}
;
/*----------------------- Structure de déclaration des variables ----------------------------*/
declarationV : type listeV PVIR declarationV
             | type listeT PVIR declarationV 
	      | mc_CONST listeC PVIR declarationV 
	      | type listeV PVIR 
	      | mc_CONST listeC PVIR 
	      | type listeT PVIR
;

type : mc_INTEGER
     | mc_FLOAT
;
ARRAY : IDF OB mc_INTEGER FB
listeT : ARRAY VIR listeT
       | ARRAY
;
listeC :  IDF op_AFF type VIR listeC
       |  IDF op_AFF type 
;
listeV : IDF VIR listeV
       | IDF op_AFF type VIR listeV
       | IDF
       | IDF op_AFF type
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
instAFF : IDF op_AFF expression
;
instIF : mc_IF PO cond PF ALO corps ALF 
       | mc_IF PO cond PF ALO corps ALF mc_ELSE ALO corps ALF
;
instWHILE : mc_WHILE PO cond PF ALO corps ALF 
;
instFOR : mc_FOR PO IDF DPOINT mc_INTEGER DPOINT mc_INTEGER DPOINT mc_INTEGER PF ALO corps ALF
;
instREADLN : mc_READLN PO IDF PF
;

instWRITELN : mc_WRITELN PO string PF 
;
string : string STR 
       | string IDF
	   |STR
	   |IDF
 ;
expression : expression op_ADD expression
           | expression op_SUB expression 
           | expression op_MUL expression
           | expression op_DIV expression 
           | PO expression PF
           | mc_INTEGER 
           | mc_FLOAT
           | IDF 
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
  return 0;
}

int yywrap()
{
return 1;
}

void yyerror(const char *s){
printf("Error: %s ligne %d colonne %d sur l'entite %s\n",s,nb_ligne, Col, yytext ? yytext :"unknown");
}

