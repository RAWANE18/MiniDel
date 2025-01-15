flex lexical.l
bison -d synt.y
gcc lex.yy.c synt.tab.c ts.c  quad.c -lfl -ly -o projetC
