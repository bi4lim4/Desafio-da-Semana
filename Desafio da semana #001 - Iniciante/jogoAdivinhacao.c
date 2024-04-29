#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int palpite, numAleatorio;
    
    srand(time(NULL));
    
    numAleatorio = rand() % 101;
    
    printf("\n\t===========| JOGO DE ADIVINHACAO |===========");
    printf("\n\t\tDica: eh um numero de 1 a 100\n\n");
    
    while (numAleatorio != palpite) {
        printf("\nDigite um palpite: ");
        scanf("%d", &palpite);
        
        if (sqrt(pow((palpite - numAleatorio), 2)) < 10 && palpite < numAleatorio)
            printf("Quase!!! Esta perto, tente um numero maior.\n");
        else if (sqrt(pow((palpite - numAleatorio), 2)) < 10 && palpite > numAleatorio)
            printf("Quase!!! Esta perto, tente um numero menor.\n");
        else if (palpite < numAleatorio)
            printf("Tente um numero maior.\n");
        else if (palpite > numAleatorio)
            printf("Tente um numero menor.\n");
        else{
        	printf("\n====================================================");
        	printf("\nParabens! voce acertou, o numero correto eh: %d\n", numAleatorio);
		}
           
    }
    
    return 0;
}
