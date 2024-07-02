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
        ehPrimo = 1; // assumindo que o número é primo
        
        if (aux < 2) {
            ehPrimo = 0; // Números menores que 2 não são primos
            printf("%d NAO eh primo\n", aux);
        } else {
            for (j = 2; j <= aux / 2; j++) {
                if (aux % j == 0) {
                    ehPrimo = 0; // Se encontrar um divisor, não é primo
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
    
    // Imprimindo todos os números primos encontrados
    printf("\nNumeros primos no vetor: ");
    for (i = 0; i < k; i++) {
        printf("%d ", vetorPrimos[i]);
    }
    printf("\n");

    return 0;
}
