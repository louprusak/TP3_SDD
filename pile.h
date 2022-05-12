#include <stdlib.h>
#include <stdio.h>

typedef int type_perso;

typedef struct pile{
    int tailleMax;
    int rangSommet;
    //type_perso *tab;
    int *tab;
}pile_t;

pile_t initPile(int t);
int estVidePile(pile_t *p);
int estPleinePile(pile_t *p);
void empiler(pile_t *p, int elt);
void depiler(pile_t *p, int *elt);
void afficherPile(pile_t *p);