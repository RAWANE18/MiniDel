%{
#include <string.h>
#include <stdio.h>
void yyerror(const char *s);
int yylex();
int yylex();
extern int nb_ligne;
extern int Col;
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

S: PROGRAM IDF VAR ALO declarationV ALF begin ALO corps ALF END  {printf("\nProgramme syntaxiquement correcte. \n"); YYACCEPT;}
;

declarationV : type listeV PVIR declarationV
		     | declarationC PVIR declarationV 
			 | declarationTab PVIR declarationV 
			 | type listeV PVIR //declaration de liste des variables
			 | declarationC PVIR //declaration d'une const
			 | declarationTab PVIR //declaration d'un tableau
;

declarationTab : type IDF OB INTEGER FB 

;
declarationC : CONST IDF AFF INTEGER
             | CONST IDF AFF FLOAT

;
type : INTEGER
     | FLOAT
;
listeV : IDF VIR listeV
       | IDF
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
	 | expression AND expression 
	 | expression OR expression 
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
  fprintf(stderr, "Error: %s ligne num %d\n", s,nb_ligne);
 
}
