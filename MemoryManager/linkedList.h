#pragma once

#include <stdbool.h>

typedef struct {
    int startAdress;
    int maxSize;
} Bloc;

typedef Bloc* Element;

struct cellule_s {
	Element val;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;

typedef Cellule* Liste;

typedef struct{
	Liste allocatedList;
	Liste freeList;
} memory_manager;

typedef memory_manager* MemoryManager;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l);

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v);

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l);

extern void afficheElement(Element e);

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l);

// version recursive
void afficheListe_r(Liste l);

extern void detruireElement(Element e);

extern bool equalsElement(Element e1, Element e2);

// Détruit tous les éléments de la liste l
// version itérative
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


//création d'un memoryManager

MemoryManager createMemoryManager(int startAddress, int maxSize);

//myAlloc
int myalloc(MemoryManager memo, int size);
//myFree
int myfree(MemoryManager memo, int address);

void readFromFile(char* filename, MemoryManager memo, int nombreDeLignes);
typedef Liste BlocList;