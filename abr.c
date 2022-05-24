//#include "abr.h"
#include "pile.h"

//Crée un arbre vide
ABR creerArbreVide(void){
    return NULL;
}

//Retourne vrai si l'abre est vide
int estArbreVide(ABR a){
    int code = 0;
    if(!a) code = 1;
    return code;
}

//Insert une valeur dans l'arbre
void insertion(ABR *a, int val){
    if(estArbreVide(*a)){
        Noeud *tmp = allouerNoeud();
        tmp->valeur = val;
        *a = tmp;
    }
    else{
        if((*a)->valeur != val){
            if(val < (*a)->valeur) insertion(&((*a)->filsgauche), val);
            if(val > (*a)->valeur) insertion(&((*a)->filsdroit), val);
        }
    }
}

//Alloue un noeud de l'abre et l'initialise
Noeud* allouerNoeud(void){
    Noeud *tmp = (Noeud*) malloc(sizeof(Noeud));
    if(!tmp){
        printf("Problème lors de l'allocation mémoire\n");
        exit(1);
    }
    tmp->filsdroit = creerArbreVide();
    tmp->filsgauche = creerArbreVide();
    return tmp;
}

//Parcours infixe de l'arbre sous forme récursive
void infixe(ABR a){
    if(!estArbreVide(a)){
        infixe(a->filsgauche);
        printf("%d\n",a->valeur);
        infixe(a->filsdroit);
    }
}

//Parcours infixe de l'arbre sous forme itérative
void infixeIteratif(ABR a){
    int fin = 0;
    ABR tmp = a;
    Pile p = creerPileVide();

    while(!fin){
        while(tmp != NULL){
            empiler(&p,tmp);
            tmp = tmp->filsgauche;
        }

        if(!estPileVide(p)){

            depiler(&p,&tmp);
            printf("%d\n",tmp->valeur);
            tmp = tmp->filsdroit;
        }
        else{
            fin = 1;
        }
    }
    
}

//Initialisation de l'arbre avec des valeurs d'un fichier
void initAbreFichier(ABR *a, char tab[], int nbval){
    int tabval[nbval];
    int i = 0;
    FILE *file = fopen(tab,"r");

    if(file){
        while(!feof(file) && i!=nbval){
            fscanf(file,"%d",&tabval[i]);
            i++;
        }
        for (int j = 0; j < i; j++)
        {
            insertion(a,tabval[j]);
        }
        
    }
}

//Retourne le hauteur de l'arbre
int hauteur(ABR a){
    int fg = 0;
    int fd = 0;

    if(!a){
        return 0;
    }  
    else{
        fg = hauteur(a->filsgauche);
        fd = hauteur(a->filsdroit);
        if(fg > fd){
            return 1+fg;
        }
        else{
            return 1+fd;
        }
    }
}

int suppr (ABR *a, int val){
    ABR cour = *a;
    ABR prec = *a;
    int code = 1;


    while(cour && cour->valeur != val){
        prec = cour;
        if (cour->valeur < val){
            cour = cour->filsdroit;
        }else{
            cour=cour->filsgauche;
        }
    }
    if (cour && cour->valeur == val){
        if(cour->filsdroit){
            if (prec->valeur>cour->valeur){
                prec->filsgauche = cour->filsdroit;
            } else {
                prec->filsdroit = cour->filsdroit;
            }
            ABR cour2 = cour->filsdroit;
            while ((cour2) && (cour2->filsgauche)){
                cour2 = cour2->filsgauche;
            }
            cour2->filsgauche=cour->filsgauche;
            free(cour);
        } else {
            if (prec->valeur>cour->valeur){
                prec->filsgauche = cour->filsgauche;
            }else{
                prec->filsdroit = cour ->filsgauche;
            }
        }
    } else {
        code = 0;
    }
    return code;
}

// void libererArbre(ABR *a){
//     if(!estArbreVide((*a)->filsdroit)) libererArbre(&((*a)->filsdroit));
//     if(!estArbreVide((*a)->filsgauche)) libererArbre(&((*a)->filsgauche));
//     if(estArbreVide((*a)->filsdroit && estArbreVide((*a)->filsgauche))) free(a);
// }



