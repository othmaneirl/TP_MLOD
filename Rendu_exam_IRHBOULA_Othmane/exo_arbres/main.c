// gcc -W -Wall -Wextra -std=c99 arbre-bin-recherche.c main.c

// gcc -W -Wall -Wextra -std=c99 arbre-bin-recherche-correction.c main.c

#include "arbre-bin-recherche.h"
// #include "arbre-bin-recherche.c"

int main(void){
	ArbreBinaire a; //,p;

	initialiser(&a);
	// a = NULL;
	// printf("estVide(a)= %s\n",estVide(a)?"TRUE":"FALSE");
	// printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));

	// a = insere_i(a,5);
	// printf("%d", a->val);
	
	// afficheGRD_r(a);printf("\n");
	a = insere_r(a,5);
	a = insere_r(a,10);
	a = insere_r(a,3);
	a = insere_r(a,2);
	a = insere_r(a,8);
	a = insere_r(a,6);
	a = insere_r(a,13);
	a = insere_r(a,34);
	a = insere_r(a,21);
	a = insere_r(a,48);

	printf("Affichage pretty:\n");
	prettyPrint(a, hauteur(a));
	return 0;
	

	detruire_r(a);

	return EXIT_SUCCESS;
}