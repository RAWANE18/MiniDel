
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_PROGRAM = 258,
     mc_VAR = 259,
     mc_begin = 260,
     mc_END = 261,
     mc_CONST = 262,
     mc_INTEGER = 263,
     mc_FLOAT = 264,
     mc_IF = 265,
     mc_ELSE = 266,
     mc_FOR = 267,
     mc_WHILE = 268,
     mc_READLN = 269,
     mc_WRITELN = 270,
     op_ADD = 271,
     op_SUB = 272,
     op_MUL = 273,
     op_DIV = 274,
     op_AND = 275,
     op_OR = 276,
     op_NOT = 277,
     op_EQ = 278,
     op_NEG = 279,
     op_INF = 280,
     op_INF_E = 281,
     op_SUP = 282,
     op_SUP_E = 283,
     op_AFF = 284,
     PO = 285,
     PF = 286,
     OB = 287,
     FB = 288,
     ALO = 289,
     ALF = 290,
     VIR = 291,
     PVIR = 292,
     DPOINT = 293,
     IDF = 294,
     ERR = 295,
     STR = 296,
     REEL = 297,
     INT = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 15 "synt.y"

    char *str; 



/* Line 1676 of yacc.c  */
#line 101 "synt.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


