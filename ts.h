#ifndef TS_H
#define TS_H

typedef struct
{
    int state;
    char name[20];
    char code[20];
    char type[20];
    char val[20];
} element;

typedef struct
{
    int state;
    char name[20];
    char type[20];
} elt;

extern element tab[200];
extern elt tabS[50], tabM[50];
extern int cpt, cpts, cptm;

void init();
void inserer(char entite[], char code[], char type[], char val[], int i, int y);
int rechercher(char entite[], char code[], char type[], char val[], int y);
void insererVal(char entite[], char val[]);
void inserertype(char entite[], char type[]);
void afficher();

#endif