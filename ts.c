/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure des TS-
/*3 types de TS:
- TS pour les IDFs & CSTs
- TS des mots clés
- TS des séparateurs. */
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

element tab[1000];
elt tabS[50], tabM[50];
int cpt, cpts, cptm;
/*1- initialisation de l'état des cases de la TS ***/
// 0: la case est libre
// 1: la case est occupée

void init()
{
    int i;
    for (i = 0; i < 1000; i++)
        tab[i].state = 0;

    for (i = 0; i < 50; i++)
    {
        tabS[i].state = 0;
        tabM[i].state = 0;
    }
    cpt = 0;
    cpts = 0;
    cptm = 0;
}

/* 2- Fonction d'insertion des entités lexicales ***/

void inserer(char entite[], char code[], char type[], char val[],int i, int y)
{
    
    switch (y)
    {
    case 0: // Insertion dans la table des IDF et CONSTANTES
        tab[i].state = 1;
        strcpy(tab[i].name, entite);
        strcpy(tab[i].code, code);
        strcpy(tab[i].type, type);
        strcpy(tab[i].val, val);
        cpt++;
        break;

    case 1: // Insertion dans la table des séparateurs
        tabS[i].state = 1;
        strcpy(tabS[i].name, entite);
        strcpy(tabS[i].type, code);
        cpts++;
        break;

    case 2: // Insertion dans la table des mots-clés
        tabM[i].state = 1;
        strcpy(tabM[i].name, entite);
        strcpy(tabM[i].type, code);
        cptm++;
        break;
    }
}

/* 3- Fonction de recherche des entités lexicales ***/

int rechercher(char entite[], char code[], char type[], char val[], int y)
{
    int i;
    switch (y)
    {
    case 0: // Table des IDF et CONST
        for (i = 0;( ( i<1000) && (tab[i].state==1)) && (strcmp(entite, tab[i].name)!=0) ; i++);
        
        if (i < 1000)
        {
            inserer(entite, code, type, val, i, 0);
        }else{
printf("entité existe déjà \n");}
        break;

    case 1: // Table des séparateurs
        for (i = 0; (( i<50) && (tabS[i].state==1)) && (strcmp(entite, tab[i].name)!=0) ;i++);
        
        if (i < 50)
        {
           inserer ( entite, code,type, val, i , 1);
        }else{
printf("entité existe déjà \n");}
        break;

    case 2: // Table des mots-clés
        for (i = 0;(( i<50) && (tabM[i].state==1)) && (strcmp(entite, tab[i].name)!=0) ;i++);
        
        if (i < 50)
        { 
               inserer ( entite, code,type, val, i , 1);
        }else{
printf("entité existe déjà \n");}
        break;

    default:
        printf("Erreur : Type de table inconnu pour l'entite '%s'.\n", entite);
        return -1;
    }
}


/* 4- Fonction d'affichages***/

void afficher()
{
    int i;

    printf("/***************Table des symboles des constantes et variables*************/\n");
    printf("____________________________________________________________________\n");
    printf("| %-11s | %-15s | %-12s | %-10s |\n", "Nom_Entite", "Code_Entite", "Type_Entite", "Val_Entite");
    printf("____________________________________________________________________\n");
    for (i = 0; i < cpt; i++)
    {
        if (tab[i].state == 1)
        {
            printf("| %-11s | %-15s | %-12s | %-10s |\n", tab[i].name, tab[i].code, tab[i].type, tab[i].val);
        }
    }

    printf("\n/***************Table des symboles mots cles*************/\n");
    printf("_____________________________________\n");
    printf("\t| NomEntite |  CodeEntite |\n");
    printf("_____________________________________\n");
    for (i = 0; i < cptm; i++)
    {
        if (tabM[i].state == 1)
        {
            printf("\t|%10s |%12s |\n", tabM[i].name, tabM[i].type);
        }
    }

    printf("\n/***************Table des symboles separateurs*************/\n");
    printf("_____________________________________\n");
    printf("\t| NomEntite |  CodeEntite |\n");
    printf("_____________________________________\n");
    for (i = 0; i < cpts; i++)
    {
        if (tabS[i].state == 1)
        {
            printf("\t|%10s |%12s |\n", tabS[i].name, tabS[i].type);
        }
    }
}