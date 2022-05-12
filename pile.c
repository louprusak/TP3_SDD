#include "pile.h"

// Initialisation de la pile
pile_t initPile(int t){
    pile_t p;
    int tab[t];
    p.tailleMax = t;
    p.rangSommet = -1;
    p.tab = tab;
    return p;
}

// Retourne vrai ou faux si la pile est vide.
int estVidePile(pile_t *p){
    int code = 0;
    if(p->rangSommet == -1){
        code = 1;
    }
    return code;
}

// Retourne vrai ou faux si la pile est pleine.
int estPleinePile(pile_t *p){
    int code = 0;
    if(p->rangSommet == p->tailleMax-1){
        code = 1;
    }
    return code;
}

// Empile une valeur au sommet de la pile.
void empiler(pile_t *p, int elt){
    printf("--- Je passe dans empiler ---\n");
    printf("%d\n",elt);
    if(!estPleinePile(p)){                    // si on n'a pas atteint la taille max
        printf("rang sommet %d\n",p->rangSommet);
        if(p->rangSommet == -1){                        // si la pile est vide   
            p->tab[0] = elt;
            printf("elt inséré %d\n",p->tab[0]);
            p->rangSommet = 0;
        }
        else{                                           // si la pile contient déjà des éléments
            p->tab[p->rangSommet+1] = elt;
            printf("elt inséré %d\n",p->tab[p->rangSommet+1]);
            p->rangSommet = p->rangSommet+1;
        }
    }
    else{                                               // taille max atteinte
        printf("Taille max atteinte, on ne peut pas insérer plus d'élements.\n");
    }
}

// Dépile une valeur du sommet de la pile.
void depiler(pile_t *p, int *elt){
    if(!estVidePile(p)){                             // si la pile n'est pas vide

        if(p->rangSommet == 0){                         // si la pile ne contient qu'un élément                           
            *elt = p->tab[0];
            p->tab[0] = -1;
            p->rangSommet = -1;
        }
        else{
            *elt = p->tab[p->rangSommet];
            p->tab[p->rangSommet] = -1;
            p->rangSommet = p->rangSommet -1;
        }
    }
    else{                                               // si la pile est vide
        printf("Impossible de dépiler car la pile est vide.\n");
        *elt = -1;
    }
}

// Affiche la pile de données.
void afficherPile(pile_t *p){

    if(!estVidePile(&p)){
        printf("base | ");
        for (int i = 0; i <= p->rangSommet; i++)
        {
            printf("%d | ",p->tab[i]);
        }
        printf("sommet\n");
    }
    else{
        printf("base | | sommet\n");
    }
}

