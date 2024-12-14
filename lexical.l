%{
#include <string.h>
#include "synt.tab.h"
extern YYSTYPE yylval;
extern int nb_ligne;
extern int Col;
extern YYSTYPE yylval;
%}

CHIFFRE           [0-9]
LETTRE          [a-zA-Z]
STR \'[^']*\'
IDF     {LETTRE}[a-z0-9_]*
INTEGER         \(-{CHIFFRE}+\)|-{CHIFFRE}+|{CHIFFRE}+
FLOAT    (\(\+{CHIFFRE}+\.{CHIFFRE}+\)|\(\-{CHIFFRE}+\.{CHIFFRE}+\)|{CHIFFRE}+\.{CHIFFRE}+)
ESPACE      [ \t]+

%%
"PROGRAM"     {Col += strlen(yytext); return PROGRAM; }
"VAR"          {Col += strlen(yytext); return VAR; }
"BEGIN"        {Col += strlen(yytext); return begin; }
"END"          {Col += strlen(yytext); return END; }
"CONST"        {Col += strlen(yytext); return CONST; }
"INTEGER"      {Col += strlen(yytext); return INTEGER; }
"FLOAT"        {Col += strlen(yytext); return FLOAT; }
"IF"           {Col += strlen(yytext); return IF; }
"ELSE"         {Col += strlen(yytext); return ELSE; }
"FOR"          {Col += strlen(yytext); return FOR; }
"WHILE"        {Col += strlen(yytext); return WHILE; }
"READLN"       {Col += strlen(yytext); return READLN; }
"WRITELN"      {Col += strlen(yytext); return WRITELN; }
"+"              {Col += strlen(yytext); return ADD; }
"-"              {Col += strlen(yytext); return SUB; }
"*"              {Col += strlen(yytext); return MUL; }
"/"              {Col += strlen(yytext); return DIV; }
"&&"              {Col += strlen(yytext); return AND; }
"||"              {Col += strlen(yytext); return OR; }
"!"              {Col += strlen(yytext); return NOT; }
"=="             {Col += strlen(yytext); return EQ; }
"!="             {Col += strlen(yytext); return NEG; }
"<"              {Col += strlen(yytext); return INF; }
"<="             {Col += strlen(yytext); return INF_E; }
">"              {Col += strlen(yytext); return SUP; }
">="             {Col += strlen(yytext); return SUP_E; }
"="              {Col += strlen(yytext); return AFF; }
"("              {Col += strlen(yytext); return PO; }
")"              {Col += strlen(yytext); return PF; }
"["              {Col += strlen(yytext); return OB; }
"]"              {Col += strlen(yytext); return FB; }
"{"              {Col += strlen(yytext); return ALO; }
"}"              {Col += strlen(yytext); return ALF; }
","              {Col += strlen(yytext); return VIR; }
";"              {Col += strlen(yytext); return PVIR; }
":"              {Col += strlen(yytext); return DPOINT; }
{STR}            {Col += strlen(yytext); return STR; }
{IDF} {
yylval.str=strdup(yytext);

			  if (yyleng>=7){ printf ("warning: %s trop long a la ligne %d a la colonne %d \n ",yytext,nb_ligne, Col);
			  return ERR;
			  }
			   Col= Col + strlen(yytext);
           
			  return IDF;

}
{INTEGER} {
yylval.entier=atoi(yytext);
 Col= Col + strlen(yytext);
   if (yytext[0] == '-' && yytext[1] != '(') {
        printf("Erreur lexicale : Ligne %d, Colonne %d, Entier signe sans parentheses : '%s'\n", nb_ligne, Col, yytext);
        return ERR;
    }
 if (atof(yytext)<-32768 || atof(yytext)>32767){
				printf("Lexical error dans %s 'Depassement de taille ' \n",yytext);
				return ERR;
				}
   return INTEGER;
}
{FLOAT} {
 yylval.reel=atof(yytext);
 if ((yytext[0] == '-'||yytext[0] == '+') && yytext[1] != '('){
        printf("Erreur lexicale : Ligne %d, Colonne %d, Reel signe sans parentheses : '%s'\n", nb_ligne, Col, yytext);
        return ERR;
    }
  Col= Col + strlen(yytext);
   return FLOAT;
}

{ESPACE}    { Col += yyleng; } {/* erreur espace*/}
\n              { nb_ligne++; Col = 1; } 
"//".*
"/*"([^*]|\*+[^/])*\*+"/"

. {
    printf("Erreur lexicale : Ligne %d, Colonne %d, Caractere non reconnu : %s\n", nb_ligne, Col, yytext);
    Col += strlen(yytext);
    return ERR;
}

%%
