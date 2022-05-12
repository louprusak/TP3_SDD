#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abr.h"

typedef struct maillonpile{
  ABR arbre;
  struct maillonpile *suiv;
}maillon_pile;

typedef maillon_pile *Pile;

typedef enum {FALSE, TRUE} Booleen;

Pile creerPileVide(void);
Booleen estPileVide(Pile p);
void empiler(Pile *ptp, ABR a);
Booleen depiler(Pile *ptp, ABR *a);
Booleen sommetPile(Pile p, ABR *a);
void afficherPile(Pile p);