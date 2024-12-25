flex lexical.l
bison -d synt.y
gcc lex.yy.c synt.tab.c ts.c -lfl -ly -o projet
