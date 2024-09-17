#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int evo1(void) {
    int a = 10;
    int *ptr = &a;
    printf("la valeur de a est %d",*ptr);
    *ptr = 4;
    printf("La nouvelle valeur de a est %d",a);
    return 0;
}

int exo2(void) {
    int tab[5]={1,2,3,4,5};
    int* ptr=tab;
    int i=0;
    while (i<5){
        printf("element numero %d: %d",i+1,(int)*(ptr+i));
        i++;
    }
    return 0;
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y=temp;
}

void exo4(void){
    int* tab =(int*) malloc(5*sizeof(int));
    for (int i=0;i<5;i++){
        printf("entre la valeur %d: \n",i+1);
        scanf("%d",(tab+i));
        printf("la valeur entree est %d \n",*(tab+i));
    }free(tab);
}

void exo5(void){
    char nom[] ="test";
    char *ptr = nom;
    int i=0;
    while (*(ptr+i)!='\0'){
        printf("le charactere %d est %c \n",i+1, *(ptr+i));
        i++;
    }printf("La taille de la chaine est %d \n", i);
}

void exo6(void){
    int a = 5;
    int* ptr = &a;
    int** ppttrr = &ptr;
    printf("la valeur de a est %d",*(*ppttrr));
}
struct Person{
        int age;
        int taille;
        char nom[50];
    };
void exo7(void){
    struct Person personne;
    personne.age=16;
    personne.taille=178;
    strcpy(personne.nom, "toto");
    struct Person* ptr=&personne;
    printf("%s a %d ans et mesure %d cm", ptr->nom,ptr->age,ptr->taille);
}
int main(void){
    exo5();
}