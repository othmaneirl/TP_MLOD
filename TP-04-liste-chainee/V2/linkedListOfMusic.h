#pragma once


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct mus {
    char* name;
    char* artist;
    char* album;
    char* genre;
    int discNumber;
    int trackNumber;
    int year;
} Music;

typedef Music* Element;

struct cellule_s {
	Element val;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;

typedef Cellule* Liste;
// lis un fichier csv contenant des musiques et les stocke dans un tableau de Music
void ReadMusic( FILE *f, Liste l, int numMusic);

// écris une musique dans un fichier csv
void PrintMusic(FILE* output, Element musique);
//écris toutes les musiques d'une liste dans un fichier csv
void PrintMusics(FILE* output, Liste l);
// retourne vrai si l est vide et faux sinon
bool estVide(Liste l);

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v);

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l);

void afficheElement(Element e);

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l);

// version recursive
void afficheListe_r(Liste l);

void detruireElement(Element e);

// // Détruit tous les éléments de la liste l
// // version itérative
void detruire_i(Liste l);

// version récursive
void detruire_r(Liste l);

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l);

// version recursive
Liste ajoutFin_r(Element v, Liste l);

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l);

// version récursive
Liste cherche_r(Element v,Liste l);

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l);

// version recursive
Liste retirePremier_r(Element v, Liste l);


void afficheEnvers_r(Liste l);
