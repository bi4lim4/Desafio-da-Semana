#include <stdio.h>
//Desafio da semana #005 - Iniciante
int main() {
    
	int N;
    printf("Digite o valor inteiro N: ");
    scanf("%d", &N);

    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    int quantidade[7] = {0};

    printf("Notas necessarias para representar %d:\n", N);

    int i;
	for (i = 0; i < 7; i++) {
        quantidade[i] = N / notas[i];
        printf("\nQuant = %i ", quantidade[i]);
        N = N % notas[i];
        printf("Resto = %i", N);
    }

	printf("\n\n");
    for (i = 0; i < 7; i++) {
        printf("%d notas de %d\n", quantidade[i], notas[i]);
    }

    return 0;
}

