%{
#include <string.h>
#include <stdio.h>
void yyerror(const char *s);
int yylex();
int nb_ligne=1;
int Col=1;
%}
%union {
    char *str;
    int entier;
    float reel;
} 
%token PROGRAM VAR begin END CONST INTEGER FLOAT IF ELSE FOR WHILE READLN WRITELN
%token ADD SUB MUL DIV AND OR NOT EQ NEG INF INF_E SUP SUP_E AFF PO PF OB FB ALO ALF VIR PVIR DPOINT AP
%token IDF ERR STR 


%nonassoc NOT
%left OR
%left AND

%left SUP SUP_E EQ NEG INF_E INF

%left ADD SUB
%left MUL DIV

%start S
%%

S: PROGRAM IDF VAR ALO declarationV ALF begin ALO corps ALF END  
{printf("\nProgramme syntaxiquement correcte. \n"); YYACCEPT;}
;

declarationV : type listeV PVIR declarationV
             | type listeT PVIR declarationV 
	      | CONST listeC PVIR declarationV 
	      | type listeV PVIR 
	      | CONST listeC PVIR 
	      | type listeT PVIR
;

type : INTEGER
     | FLOAT
;
ARRAY : IDF OB INTEGER FB
listeT : ARRAY VIR listeT
       | ARRAY
;
listeC :  IDF AFF type VIR listeC
       |  IDF AFF type 
;
listeV : IDF VIR listeV
       | IDF AFF type VIR listeV
       | IDF
       | IDF AFF type
;
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
instAFF : IDF AFF expression
;
instIF : IF PO cond PF ALO corps ALF 
       | IF PO cond PF ALO corps ALF ELSE ALO corps ALF
;
instWHILE : WHILE PO cond PF ALO corps ALF 
;
instFOR : FOR PO IDF DPOINT INTEGER DPOINT INTEGER DPOINT INTEGER PF ALO corps ALF
;
instREADLN : READLN PO IDF PF
;

instWRITELN : WRITELN PO string PF 
;
string : string STR 
       | string IDF
	   |STR
	   |IDF
 ;
expression : expression ADD expression
           | expression SUB expression 
           | expression MUL expression
           | expression DIV expression 
           | PO expression PF
           | INTEGER 
           | FLOAT
           | IDF 
;
cond : expression EQ expression 
     | expression NEG expression 
     | expression INF expression 
     | expression SUP expression 
     | expression INF_E expression 
     | expression SUP_E expression 
     | PO expression PF AND PO expression PF
     | PO expression PF OR PO expression PF
     | PO NOT expression PF
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

//Erreur GLOB AMROUSS 
void yyerror(const char *s){
printf("%s ligne %d colonne %d",s,nb_ligne, Col);
}
