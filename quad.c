#include <stdbool.h>
#include "quad.h"
qdr quad[1000];
int qc = 0; // Initialize the counter
extern bool logic;
void quadr(char opr[], char op1[], char op2[], char res[])
{
    strcpy(quad[qc].oper, opr);
    strcpy(quad[qc].op1, op1);
    strcpy(quad[qc].op2, op2);
    strcpy(quad[qc].res, res);
    qc++;
}

void ajour_quad(int num_quad, int colon_quad, char val[])
{
    if (colon_quad == 0)
        strcpy(quad[num_quad].oper, val);
    else if (colon_quad == 1)
        strcpy(quad[num_quad].op1, val);
    else if (colon_quad == 2)
        strcpy(quad[num_quad].op2, val);
    else if (colon_quad == 3)
        strcpy(quad[num_quad].res, val);
}

void afficher_qdr()
{
    printf("*********************Les Quadruplets***********************\n");
    int i;
    for (i = 0; i < qc; i++)
    {
        printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )", i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res);
        printf("\n--------------------------------------------------------\n");
    }
}

int tempVarCount = 0; 
char *newTempVar()
{
    static char temp[10];
    sprintf(temp, "t%d", tempVarCount++);
    return strdup(temp); 
}
/**********************************conversion d'un int en chaine de caractere******************************/
char *convert(int i)
{
    char s[15];
    sprintf(s, "%d", i);
    return strdup(s);
}
/***********************************Quads Expression logiques************************************************/
void quadL(int l,int j, char *b, char *c, char *d ,bool logic)
{      // j quelle expression? BE BG BL ....
    if(logic)
    {  switch (j)
    {
    case 1: 
        quadr("BG", b, c, d);
        break;
    case 2: 
         quadr("BGE", b, c, d);
        break;
    case 3:
        quadr("BL", b, c, d);
        break;
    case 4: 
        quadr("BLE", b, c, d);
        break;
    case 5: 
        quadr("BE", b, c, d);
        break;
    case 6: 
        quadr("BNE", b, c, d);
        break;
    }}
    else 
    {quadC(j,b,c,d);}

   
}


/***********************************Quads Expressions de comparaison************************************************/
void quadC(int i, char *b, char *c, char *d)
{
    switch (i)
    {
    case 1: 
        quadr("BLE", b, c, d);
        break;
    case 2: // >=
         quadr("BL", b, c, d);
        break;
    case 3: // <
        quadr("BGE", b, c, d);
        break;
    case 4: // <=
        quadr("BG", b, c, d);
        break;
    case 5: // ==
        quadr("BNE", b, c, d);
        break;
    case 6: // !=
        quadr("BE", b, c, d);
        break;
    }
}