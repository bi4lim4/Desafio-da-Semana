#include <stdio.h>

int main() {
    int i, j, N, aux, k = 0, ehPrimo;
    
    printf ("\n\t PROGRAMA PARA IDENTIFICAR NUMEROS PRIMOS\n\n");
    
    printf("Digite quantos numeros deseja colocar no vetor: ");
    scanf("%i", &N);
    
    int numeros[N], vetorPrimos[N];
    
    for (i = 0; i < N; i++) {
        printf("\nDigite um numero inteiro: ");
        scanf("%i", &numeros[i]);
        
        aux = numeros[i];
        ehPrimo = 1; // assumindo que o n�mero � primo
        
        if (aux < 2) {
            ehPrimo = 0; // N�meros menores que 2 n�o s�o primos
            printf("%d NAO eh primo\n", aux);
        } else {
            for (j = 2; j <= aux / 2; j++) {
                if (aux % j == 0) {
                    ehPrimo = 0; // Se encontrar um divisor, n�o � primo
                    printf("%d NAO eh primo\n", aux);
                    break;
                }
            }
        }
        
        if (ehPrimo) {
            vetorPrimos[k] = aux;
            printf("%d eh primo\n", aux);
            k++;
        }
    }
    
    // Imprimindo todos os n�meros primos encontrados
    printf("\nNumeros primos no vetor: ");
    for (i = 0; i < k; i++) {
        printf("%d ", vetorPrimos[i]);
    }
    printf("\n");

    return 0;
}
