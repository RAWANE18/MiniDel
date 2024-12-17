#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void inserer(char entite[], char code[], char type[], char val[], int i, int y)
{

    switch (y)
    {
    case 0: //  table des IDF et CONSTANTES
        tab[i].state = 1;
        strcpy(tab[i].name, entite);
        strcpy(tab[i].code, code);
        strcpy(tab[i].type, type);
        strcpy(tab[i].val, val);
        cpt++;
        break;

    case 1: // table des séparateurs
        tabS[i].state = 1;
        strcpy(tabS[i].name, entite);
        strcpy(tabS[i].type, code);
        cpts++;
        break;

    case 2: // la table des mots-clés
        tabM[i].state = 1;
        strcpy(tabM[i].name, entite);
        strcpy(tabM[i].type, code);
        cptm++;
        break;
    }
}

int rechercher(char entite[], char code[], char type[], char val[], int y)
{
    int i;
    switch (y)
    {
    case 0: // Table des IDF et CONST
        for (i = 0; i < 1000 && tab[i].state == 1; i++)
        {
            if (strcmp(entite, tab[i].name) == 0)
            {
                return i;
            }
        }
        if (i < 1000)
        {
            inserer(entite, code, type, val, i, 0);
        }
        break;

    case 1: // Table des séparateurs
        for (i = 0; i < 50 && tabS[i].state == 1; i++)
        {
            if (strcmp(entite, tabS[i].name) == 0)
            {
                return i;
            }
        }
        if (i < 50)
        {
            inserer(entite, code, "", "", i, 1);
        }
        break;

    case 2: // Table des mots-clés
        for (i = 0; i < 50 && tabM[i].state == 1; i++)
        {
            if (strcmp(entite, tabM[i].name) == 0)
            {
                return i;
            }
        }
        if (i < 50)
        {
            inserer(entite, code, "", "", i, 2);
        }
        break;

    default:
        printf("Erreur : Type de table inconnu pour l'entite '%s'.\n", entite);
        return -1;
    }
}

void afficher()
{
    int i;

    printf("\n \t ---> Table des symboles des constantes et variables\n");
    printf("\t_____________________________________________________________\n");
    printf("\t| %-11s | %-15s | %-12s | %-10s |\n", "Nom_Entite", "Code_Entite", "Type_Entite", "Val_Entite");
    printf("\t|-------------|-----------------|--------------|------------|\n");
    for (i = 0; i < cpt; i++)
    {
        if (tab[i].state == 1)
        {
            printf("\t| %-11s | %-15s | %-12s | %-10s |\n", tab[i].name, tab[i].code, tab[i].type, tab[i].val);
            printf("\t|-------------|-----------------|--------------|------------|\n");
        }
    }

    printf("\n \t ---> Table des symboles mots cles \n");
    printf("\t___________________________\n");
    printf("\t| NomEntite |  CodeEntite |\n");
    printf("\t|-----------|-------------|\n");
    for (i = 0; i < cptm; i++)
    {
        if (tabM[i].state == 1)
        {
            printf("\t|%10s |%12s |\n", tabM[i].name, tabM[i].type);
            printf("\t|-----------|-------------|\n");
        }
    }

    printf("\n \t ---> Table des symboles separateurs\n");
    printf("\t___________________________\n");
    printf("\t| NomEntite |  CodeEntite |\n");
    printf("\t|-----------|-------------|\n");
    for (i = 0; i < cpts; i++)
    {
        if (tabS[i].state == 1)
        {
            printf("\t|%10s |%12s |\n", tabS[i].name, tabS[i].type);
            printf("\t|-----------|-------------|\n");
        }
    }
}