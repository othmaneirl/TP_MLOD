//exercice créé avec chatgpt
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    char *nom;
    char *prenom;
    int age;
    float moyenne;
} Etudiant;

typedef Etudiant* Element;

struct cellule_s {
	Element val;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;

typedef Cellule* Liste;

// Prototypes des fonctions à implémenter
Liste creerCellule(Element etudiant){
    Liste liste = malloc(sizeof(Cellule));
    liste->val = etudiant;
	liste->suiv=NULL;
	return liste;
}
void ajouterEtudiant(Liste liste, Element etudiant){
    Liste nouvelleCellule = creerCellule(etudiant);
    nouvelleCellule->suiv = liste;
    return nouvelleCellule;
}

void afficheElement(Element e) {      //affiche un element de type void*
    printf("L'etudiant %s %s a %d ans et a %f de moyenne\n",e->nom,e->prenom,e->age, e->moyenne);  // a faire
}

void afficheliste(Liste l) {
	printf("[ ");
	while(l != NULL){
		afficheElement(l->val);
		l = l->suiv;
	}printf(" ]");
}
void libererListe(Liste tete) {
    Liste tmp;
    while (tete != NULL) {
        tmp = tete;
        tete = tete->suiv;
        free(tmp->val->nom);
        free(tmp->val->prenom);
        free(tmp);
    }
}

int main() {
    // Déclaration de la liste chaînée (initialement vide)
    Cellule *liste = NULL;

    // Création et ajout des étudiants à la liste (à compléter)
    
    // Affichage de la liste (à compléter)

    // Libération de la mémoire (à compléter)

    return 0;
}
