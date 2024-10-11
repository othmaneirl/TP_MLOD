#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire arbre = malloc(sizeof(Noeud));
	arbre->val = e;
	arbre->filsGauche = NULL;
	arbre->filsDroit = NULL;
	return arbre;
}
// insère e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un élément e, ce dernier n'est pas inséré afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire parent = NULL;
	ArbreBinaire actuel = a;
	while (!estVide(actuel)){
		parent = actuel;
		if (actuel->val == e){
			return a;
		}else if (actuel->val >= e){
			actuel = actuel->filsGauche;
		}else{
			actuel = actuel->filsDroit;
		}
	}
	if (estVide(parent)){
		return creer(e);
	}else if(parent->val>=e){
		parent->filsGauche = creer(e);
	}else {
		parent->filsDroit = creer(e);
	}
	return a;
}
// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if (estVide(a)){
		return creer(e);
	}else if (a->val >= e){
		a->filsGauche = insere_r(a->filsGauche, e);
	}else if (a->val < e){
		a->filsDroit = insere_r(a->filsDroit, e);
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){

		return 0;
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if (estVide(a)) {
		return -1;
	}
	int profondeur = 0;
	while (a != NULL) {
		if (a->val == e) {
			return profondeur;
		} else if (a->val > e) {
			a = a->filsGauche;
		} else {
			a = a->filsDroit;
		}
		profondeur++;
	}
	return -1;
}


// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a) {
	if (estVide(a)) {
		return -1;
	} else {
		int hauteurGauche = hauteur(a->filsGauche);
		int hauteurDroite = hauteur(a->filsDroit);
		if (hauteurGauche > hauteurDroite) {
			return hauteurGauche + 1;
		} else {
			return hauteurDroite + 1;
		}
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	return NULL;
}

void afficheElement(Element e) {      //affiche un element de type void*
	printf("%d",e);  // a faire
}
void afficheRGD_r(ArbreBinaire a){
	
}


void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("(");
		afficheRGD_r(a->filsGauche);
		afficheElement(a->val);
		afficheRGD_r(a->filsDroit);
		printf(")");
	}
}

void prettyPrint(ArbreBinaire a,int h) {
	for (int i=0; i<(h - hauteur(a));i++){
		printf("|--");
	}
	if (estVide(a)) {
		printf("X\n");
		return;
	}
	printf("%d\n", a->val);
	prettyPrint(a->filsDroit, h);
	prettyPrint(a->filsGauche, h);
	
}


void afficheGDR_r(ArbreBinaire a){
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

