// exercice créé avec chatgpt
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *nom;
    char *prenom;
    int ID; //doit etre unique
    float salaire; 
} Employe;

typedef Employe* Element;

struct cellule_s {
    Element val;
    struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;
typedef Cellule* Liste;

// Fonction pour créer une nouvelle cellule
Liste creerElement(Element employe) {
    Liste liste = malloc(sizeof(Cellule));
    liste->val = employe;
    liste->suiv = NULL;
    return liste;
}

// Fonction pour créer un nouvel employé
Liste creerEmploye(char* nom, char* prenom, int ID, float salaire) {
    Element employe = malloc(sizeof(Employe));
    employe->nom = malloc(strlen(nom) + 1);
    strcpy(employe->nom, nom);
    employe->prenom = malloc(strlen(prenom) + 1);
    strcpy(employe->prenom, prenom);
    employe->ID = ID;
    employe->salaire = salaire;
    return creerElement(employe);
}

// Fonction pour ajouter un employé à la liste (trié par nom)
Liste ajouterEmploye(Liste liste, Element employe) {
    if (liste == NULL || strcmp(employe->nom, liste->val->nom) < 0) {
        Liste nouvelleCellule = creerElement(employe);
        nouvelleCellule->suiv = liste;
        return nouvelleCellule;  
    }

    Liste temp = liste;
    while (temp->suiv != NULL && strcmp(employe->nom, temp->suiv->val->nom) > 0) {
        temp = temp->suiv;
    }

    Liste nouvelleCellule = creerElement(employe);
    nouvelleCellule->suiv = temp->suiv;
    temp->suiv = nouvelleCellule;

    return liste;
}

// Fonction pour chercher un employé par son ID
Element chercherEmploye(Liste tete, int ID) {
    Liste actuel = tete;
    while (actuel != NULL) {
        if (actuel->val->ID == ID) {
            return actuel->val;
        }
        actuel = actuel->suiv;
    }
    return NULL;  // Si l'employé n'est pas trouvé
}

// Fonction pour afficher un employé
void afficheElement(Element e) {
    printf("Nom: %s, Prenom: %s, ID: %d, Salaire: %.2f\n", e->nom, e->prenom, e->ID, e->salaire);
}

// Fonction pour afficher toute la liste
void afficherListe(Liste l) {
    printf("[\n");
    while (l != NULL) {
        afficheElement(l->val);
        l = l->suiv;
    }
    printf("]\n");
}

// Fonction pour supprimer un employé par son ID
Liste supprimerEmploye(Liste liste, int ID) {
    Liste actuel = liste;
    Liste precedent = NULL;

    while (actuel != NULL && actuel->val->ID != ID) {
        precedent = actuel;
        actuel = actuel->suiv;
    }

    // Si l'employé n'est pas trouvé
    if (actuel == NULL) {
        printf("Employe avec ID %d non trouve.\n", ID);
        return liste;
    }

    // Si l'employé est en tête de la liste
    if (precedent == NULL) {
        Liste nouvelleTete = actuel->suiv;
        free(actuel->val->nom);
        free(actuel->val->prenom);
        free(actuel->val);
        free(actuel);
        return nouvelleTete;
    }

    precedent->suiv = actuel->suiv;
    free(actuel->val->nom);
    free(actuel->val->prenom);
    free(actuel->val);
    free(actuel);

    return liste;
}

// Fonction pour mettre à jour le salaire d'un employé par son ID
void mettreAJourSalaire(Liste tete, int ID, float nouveauSalaire) {
    Element employe = chercherEmploye(tete, ID);

    if (employe == NULL) {
        printf("Employe avec ID %d non trouve.\n", ID);
        return;
    }

    employe->salaire = nouveauSalaire;
    printf("Salaire mis a jour pour l'employe avec ID %d.\n", ID);
}

// Fonction pour libérer la mémoire de la liste
void libererListe(Liste tete) {
    Liste actuel = tete;

    while (actuel != NULL) {
        Liste temp = actuel;
        actuel = actuel->suiv;

        // Libération de l'employé et de la cellule
        free(temp->val->nom);
        free(temp->val->prenom);
        free(temp->val);
        free(temp);
    }
}

int main() {
    // Déclaration de la liste chaînée
    Liste liste = NULL;

    // Ajout d'employés
    liste = ajouterEmploye(liste, creerEmploye("Dupont", "Jean", 101, 2500.50));
    liste = ajouterEmploye(liste, creerEmploye("Martin", "Sophie", 102, 3200.75));
    liste = ajouterEmploye(liste, creerEmploye("Durand", "Alice", 103, 2800.30));

    // Affichage de la liste
    printf("Liste des employes:\n");
    afficherListe(liste);

    // Recherche d'un employé par ID
    int idRecherche = 102;
    Element employeTrouve = chercherEmploye(liste, idRecherche);
    if (employeTrouve != NULL) {
        printf("Employe trouve: %s %s, ID: %d, Salaire: %.2f\n",
               employeTrouve->nom, employeTrouve->prenom, employeTrouve->ID, employeTrouve->salaire);
    } else {
        printf("Employe avec ID %d non trouve.\n", idRecherche);
    }

    // Mise à jour du salaire d'un employé
    mettreAJourSalaire(liste, 101, 2700.00);

    // Suppression d'un employé
    liste = supprimerEmploye(liste, 102);

    // Affichage de la liste après suppression
    printf("Liste des employes apres suppression:\n");
    afficherListe(liste);

    // Libération de la liste
    libererListe(liste);

    return 0;
}
