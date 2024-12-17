%{
#include <string.h>
#include "synt.tab.h"
extern YYSTYPE yylval;
extern int nb_ligne;
extern int Col;
int index;
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

"PROGRAM"     {index = rechercher(yytext, "Mot cle", "", "", 2); Col += strlen(yytext); return mc_PROGRAM; }
"VAR"          {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_VAR; }
"BEGIN"        {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_begin; }
"END"          {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_END; }
"CONST"        {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_CONST; }
"INTEGER"      {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_INTEGER; }
"FLOAT"        {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_FLOAT; }
"IF"           {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_IF; }
"ELSE"         {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_ELSE; }
"FOR"          {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_FOR; }
"WHILE"        {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_WHILE; }
"READLN"       {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_READLN; }
"WRITELN"      {index = rechercher(yytext, "Mot cle", "", "", 2);Col += strlen(yytext); return mc_WRITELN; }
"+"              {index = rechercher(yytext, "Separateur", "", "", 1); Col += strlen(yytext); return op_ADD; }
"-"              {index = rechercher(yytext, "Separateur", "", "", 1); Col += strlen(yytext); return op_SUB; }
"*"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_MUL; }
"/"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_DIV; }
"&&"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_AND; }
"||"             { index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_OR; }
"!"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_NOT; }
"=="             {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_EQ; }
"!="             {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_NEG; }
"<"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_INF; }
"<="             {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_INF_E; }
">"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_SUP; }
">="             {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_SUP_E; }
"="              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return op_AFF; }
"("              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return PO; }
")"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return PF; }
"["              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return OB; }
"]"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return FB; }
"{"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return ALO; }
"}"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return ALF; }
","              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return VIR; }
";"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return PVIR; }
":"              {index = rechercher(yytext, "Separateur", "", "", 1);Col += strlen(yytext); return DPOINT; }
{STR}            {Col += strlen(yytext); return STR; }
{IDF} {

			  if (yyleng>=7){ printf ("warning: %s trop long a la ligne %d a la colonne %d \n ",yytext,nb_ligne, Col);
      
			  return ERR;
			  }
        yylval.str=strdup(yytext);
			   Col= Col + strlen(yytext);
          index=rechercher(yytext, "Identificateur", "IDF", yylval.str, 0);
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
         index=rechercher(yytext, "Variable", "INTEGER", yylval.entier, 0);
   return mc_INTEGER;
}

{FLOAT} {
 yylval.reel=atof(yytext);
 if ((yytext[0] == '-'||yytext[0] == '+') && yytext[1] != '('){
        printf("Erreur lexicale : Ligne %d, Colonne %d, Reel signe sans parentheses : '%s'\n", nb_ligne, Col, yytext);
        return ERR;
    }
  Col= Col + strlen(yytext);
      index=rechercher(yytext, "Variable", "FLOAT", yylval.reel, 0);
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

