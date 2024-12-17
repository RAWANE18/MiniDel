%{
#include <string.h>
#include "synt.tab.h"
#include "ts.h"
extern YYSTYPE yylval;
extern int nb_ligne;
extern int Col;
int idx;
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

"PROGRAM"     {idx = rechercher(yytext, "Mot cle", "", "", 2); Col += strlen(yytext); return mc_PROGRAM; }
"VAR"          {idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_VAR; }
"BEGIN"        {idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_begin; }
"END"          {idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_END; }
"IF"           {idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_IF; }
"ELSE"         {idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_ELSE; }
"FOR"          {idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_FOR; }
"WHILE"        {idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_WHILE; }
"READLN"       {idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_READLN; }
"WRITELN"      {idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_WRITELN; }
"CONST"        {yylval.str=strdup("CONST"); idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_CONST; }
"INTEGER"      {yylval.str=strdup("INTEGER"); idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_INTEGER; }
"FLOAT"        {yylval.str=strdup("FLOAT"); idx = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_FLOAT; }
"+"              {idx = rechercher(yytext, "Separateur", "", "", 1); Col += strlen(yytext); return op_ADD; }
"-"              {idx = rechercher(yytext, "Separateur", "", "", 1); Col += strlen(yytext); return op_SUB; }
"*"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_MUL; }
"/"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_DIV; }
"&&"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_AND; }
"||"             { idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_OR; }
"!"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_NOT; }
"=="             {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_EQ; }
"!="             {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_NEG; }
"<"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_INF; }
"<="             {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_INF_E; }
">"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_SUP; }
">="             {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_SUP_E; }
"="              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_AFF; }
"("              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return PO; }
")"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return PF; }
"["              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return OB; }
"]"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return FB; }
"{"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return ALO; }
"}"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return ALF; }
","              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return VIR; }
";"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return PVIR; }
":"              {idx = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return DPOINT; }
{STR}            {Col += strlen(yytext); return STR; }
{IDF} {

			  if (yyleng>=7){ printf ("warning: %s trop long a la ligne %d a la colonne %d \n ",yytext,nb_ligne, Col);
			  return ERR;
			  }
        yylval.str=strdup(yytext);
			   Col= Col + strlen(yytext);
        idx=rechercher(yytext, "Identificateur", "", "", 0);
			  return IDF;

}

{INTEGER} {
 Col= Col + strlen(yytext);
   if (yytext[0] == '-' && yytext[1] != '(') {
        printf("Erreur lexicale : Ligne %d, Colonne %d, Entier signe sans parentheses : '%s'\n", nb_ligne, Col, yytext);
        return ERR;
    }
 if (atof(yytext)<-32768 || atof(yytext)>32767){
				printf("Lexical error dans %s 'Depassement de taille ' \n",yytext);
				return ERR;
				}
        char value[20];
                      sprintf(value, "%d", atoi(yytext));
         idx=rechercher(yytext, "Variable", "INTEGER", value, 0);
   return mc_INTEGER;
}

{FLOAT} {
 if ((yytext[0] == '-'||yytext[0] == '+') && yytext[1] != '('){
        printf("Erreur lexicale : Ligne %d, Colonne %d, Reel signe sans parentheses : '%s'\n", nb_ligne, Col, yytext);
        return ERR;
    }
  Col= Col + strlen(yytext);
  
      idx=rechercher(yytext, "Variable", "FLOAT",yytext, 0);
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
