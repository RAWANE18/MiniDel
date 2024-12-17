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

"PROGRAM"     {Col += strlen(yytext); return mc_PROGRAM; }
"VAR"          {Col += strlen(yytext); return mc_VAR; }
"BEGIN"        {Col += strlen(yytext); return mc_begin; }
"END"          {Col += strlen(yytext); return mc_END; }
"CONST"        {Col += strlen(yytext); return mc_CONST; }
"INTEGER"      {Col += strlen(yytext); return mc_INTEGER; }
"FLOAT"        {Col += strlen(yytext); return mc_FLOAT; }
"IF"           {Col += strlen(yytext); return mc_IF; }
"ELSE"         {Col += strlen(yytext); return mc_ELSE; }
"FOR"          {Col += strlen(yytext); return mc_FOR; }
"WHILE"        {Col += strlen(yytext); return mc_WHILE; }
"READLN"       {Col += strlen(yytext); return mc_READLN; }
"WRITELN"      {Col += strlen(yytext); return mc_WRITELN; }
"+"              {Col += strlen(yytext); return op_ADD; }
"-"              {Col += strlen(yytext); return op_SUB; }
"*"              {Col += strlen(yytext); return op_MUL; }
"/"              {Col += strlen(yytext); return op_DIV; }
"&&"              {Col += strlen(yytext); return op_AND; }
"||"              {Col += strlen(yytext); return op_OR; }
"!"              {Col += strlen(yytext); return op_NOT; }
"=="             {Col += strlen(yytext); return op_EQ; }
"!="             {Col += strlen(yytext); return op_NEG; }
"<"              {Col += strlen(yytext); return op_INF; }
"<="             {Col += strlen(yytext); return op_INF_E; }
">"              {Col += strlen(yytext); return op_SUP; }
">="             {Col += strlen(yytext); return op_SUP_E; }
"="              {Col += strlen(yytext); return op_AFF; }
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

			  if (yyleng>=7){ printf ("warning: %s trop long a la ligne %d a la colonne %d \n ",yytext,nb_ligne, Col);
      
			  return ERR;
			  }
        yylval.str=strdup(yytext);
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
   return mc_INTEGER;
}

{FLOAT} {
 yylval.reel=atof(yytext);
 if ((yytext[0] == '-'||yytext[0] == '+') && yytext[1] != '('){
        printf("Erreur lexicale : Ligne %d, Colonne %d, Reel signe sans parentheses : '%s'\n", nb_ligne, Col, yytext);
        return ERR;
    }
  Col= Col + strlen(yytext);
   return mc_FLOAT;
}


{ESPACE}    { Col += yyleng; } 
\n              { nb_ligne++; Col = 1; } 
"//".*
"/*"([^*]|\*+[^/])*\*+"/"


. {
    printf("Erreur lexicale : Ligne %d, Colonne %d, Caractere non reconnu : %s\n", nb_ligne, Col, yytext);
    Col += strlen(yytext);
    return ERR;
}

%%

