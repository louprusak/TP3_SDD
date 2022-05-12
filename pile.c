#include "pile.h"

Pile creerPileVide(void){
  return NULL;
}

Booleen estPileVide(Pile p){
  if(p==NULL)return TRUE;
  return FALSE;
}

void empiler(Pile *ptp, ABR a){
  maillon_pile* tmp;
  tmp=(maillon_pile*)malloc(sizeof(maillon_pile));
  if(tmp==NULL){
    printf("Problème d'allocation mémoire !\n");
    exit(1);
  }
  tmp->arbre = a;
  tmp->suiv = *ptp;
  *ptp = tmp;
}

Booleen depiler(Pile *ptp, ABR *a){
  maillon_pile *tmp;
  if(estPileVide(*ptp)){
    printf("dépiler impossible car la pile est vide !\n");
    return FALSE;
  }
  tmp = *ptp;
  *ptp = tmp->suiv;
  *a = tmp->arbre;
  free(tmp);
  return TRUE;
}

Booleen sommetPile(Pile p, ABR *a){
  if(estPileVide(p)){
    printf("impossible car la liste est vide !\n");
    return FALSE;
  }
  *a = p->arbre;
  return TRUE;
}

void afficherPile(Pile p){
	while(!estPileVide(p)){
	
		printf("%d ",(int) p->arbre);
		p=p->suiv;
	}
	printf("\n");
}