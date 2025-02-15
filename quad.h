// quad.h
#ifndef QUAD_H
#define QUAD_H

#include <stdio.h>
#include <string.h>

typedef struct qdr {
    char oper[100]; 
    char op1[100];   
    char op2[100];   
    char res[100];  
} qdr;

extern qdr quad[1000];
extern int qc;
extern int tempVarCount; 

void quadL(int l,int j, char *b, char *c, char *d,bool logic);
void quadC(int i, char* b, char* c, char* d);
void quadr(char opr[], char op1[], char op2[], char res[]);
void ajour_quad(int num_quad, int colon_quad, char val[]);
void afficher_qdr();
char* newTempVar();

#endif // QUAD_H