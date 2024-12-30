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

element tab[200];
elt tabS[50], tabM[50];
int cpt, cpts, cptm;

void init()
{
    int i;
    for (i = 0; i < 200; i++)
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
        for (i = 0; i < 200 && tab[i].state == 1; i++)
        {
            if (strcmp(entite, tab[i].name) == 0)
            {

                return i;
            }
        }
        if (i < 200)
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
void insererVal(char entite[], char val[])
{
    int pos;
    pos = rechercher(entite, "", "", "", 0);
    if (pos != -1)
    {
        strcpy(tab[pos].val, val);
    }
    
  
}

int declarer(char entite[])
{
    for (int i = 0; i < 200 && tab[i].state == 1; i++)
    {
        if (strcmp(tab[i].code, "Identificateur") == 0 && strcmp(entite, tab[i].name) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int div_zero(char entite[], char operand[])
{
    if (strcmp(operand, "/") == 0)
    {
        if (strcmp(entite, "0") == 0)
        {
            return 1;
        }
        int pos;
        pos = rechercher(entite, "Identificateur", "", "", 0);
        if (pos != -1 && strcmp(tab[pos].val, "0") == 0)
        {

            return 1;
        }
    }
    return 0;
}
int verefier_cst(char entite[]){
for (int i = 0; i < 200 && tab[i].state == 1; i++)
    {
        if (strcmp(tab[i].code, "Identificateur") == 0 && strcmp(entite, tab[i].name) == 0&&strcmp(tab[i].type, "CONSTANTE") == 0)
        {
            return 1;
        }
    }
}
int affect_value(char operand1[], char operand2[], char operator[], char result[]) {
char val[20]; 
float res;    
char type1[20];
char type2[20];
char type3[20]; 
int pos;
    for (int i = 0; i < 200 && tab[i].state == 1; i++) {
        if (strcmp(tab[i].code, "Identificateur") == 0) {
             if (strcmp(result, tab[i].name) == 0) {
                strcpy(type3, tab[i].type);
                pos=i;
            }
            if (strcmp(operand1, tab[i].name) == 0) {
                strcpy(operand1, tab[i].val);
                strcpy(type1, tab[i].type);
                
            }
            if (strcmp(operand2, tab[i].name) == 0) {
                strcpy(operand2, tab[i].val);
                strcpy(type2, tab[i].type);
               
            }
        }
    }

    float op1 = strtof(operand1, NULL);
    float op2 = strtof(operand2, NULL);

    if (strcmp(operator, "+") == 0) {
        
        res = op1 + op2;
         snprintf(val, sizeof(val), "%.0f", res); 
    } else if (strcmp(operator, "-") == 0) {
        res = op1 - op2;
         snprintf(val, sizeof(val), "%.0f", res); 
    } else if (strcmp(operator, "*") == 0) {
        res = op1 * op2;
         snprintf(val, sizeof(val), "%.0f", res); 
    } else if (strcmp(operator, "/") == 0) {
       
        if (op2 == 0) {
            return -1;
        }
        res = op1/op2;
         if((strcmp(type3, "INTEGER")==0)){
 snprintf(val, sizeof(val), "%.0f", res); 
        }else{ snprintf(val, sizeof(val), "%.2f", res); }
        
    } else {
        printf("Error: Unknown operator '%s'\n", operator);
        return 2;
    }

    
      strcpy(tab[pos].val,val);
 

     
 if((strcmp(type3, "INTEGER")==0)&&(strcmp(type1, "FLOAT")==0||strcmp(type2, "FLOAT")==0)){
            return 1;
        }
     
       
    
    return 0;
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