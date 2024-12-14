flex lexical.l
bison -d tp1exo1.y
gcc lex.yy.c synt.tab.c -lfl -ly -o lexical