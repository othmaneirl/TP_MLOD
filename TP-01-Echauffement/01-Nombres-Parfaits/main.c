#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool estParfait(int i) { 
    int somme = 0;
    for(int j=1;j<i;j++)
        if(i%j==0)
            somme+=j;
    return somme==i;
}
void afficheParfait(int N){
        for (int i=1; i<=N; i++)
            if (estParfait(i))
            printf("%d\n", i);
    }
int main (void)
{
    int N;
    scanf("%d", &N);
    afficheParfait(N);
	return EXIT_SUCCESS;
}