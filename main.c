#include "abr.h"

int main(void){
    ABR a = creerArbreVide();
    if(estArbreVide(a)) printf("arbre vide\n");
    Noeud *n = allouerNoeud();
    n->valeur = 1;
    //printf("%d\n",n->valeur);
    n->filsgauche = NULL;
    n->filsdroit = NULL;

    // insertion(&a, 1);
    // insertion(&a, 3);
    // insertion(&a, 5);
    // insertion(&a, 2);
    // insertion(&a, 10);
    // insertion(&a, 8);

    initAbreFichier(&a, "val.txt", 50);

    //infixe(a);

    infixeIteratif(a);
    //libererArbre(&a);
    return 0;
}