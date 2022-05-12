#include <stdio.h>
#include <stdlib.h>


typedef struct noeud{
    int valeur;
    struct noeud *filsgauche;
    struct noeud *filsdroit;
}Noeud;

typedef Noeud* ABR;

ABR creerArbreVide(void);
int estArbreVide(ABR a);
Noeud* allouerNoeud(void);
void infixe(ABR a);
void infixeIteratif(ABR a);
void insertion(ABR *a, int val);
//void libererArbre(ABR *a);
void initAbreFichier(ABR *a, char tab[], int nbval);