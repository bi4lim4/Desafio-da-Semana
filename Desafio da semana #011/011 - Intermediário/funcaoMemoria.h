#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX1 4
#define MAX2 5
#define VAZIO '.'

char tabuleiro1[MAX1][MAX2];
char tabuleiro2[MAX1][MAX2];

int coordH[MAX2] = {1, 2, 3, 4};
int coordV[MAX1] = {1, 2, 3};

void iniciaTabuleiro() {
    int i, j;

    for (i = 0; i < MAX1; i++) {
        for (j = 0; j < MAX2; j++) {
            tabuleiro1[i][j] = VAZIO;
            tabuleiro2[i][j] = VAZIO;
        }
    }
}

void imprimeTabuleiro() {
    int i, j;

    printf("\n\n");
    printf("\t       ---------------\n");
    printf("\t         |");
    for (i = 0; i < MAX1; i++) {
        printf("%3d", coordH[i]);
    }
    printf("\n\t       --+------------\n");

    for (i = 1; i < MAX1; i++) {
        printf("\t       %2d|", coordV[i - 1]);
        for (j = 1; j < MAX2; j++) {
            printf("  %c", tabuleiro1[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void embaralhaCartas() {
    char cartas[] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F'};
    int i, j, k = 0;

    srand(time(NULL));

    for (i = 1; i < MAX1; i++) {
        for (j = 1; j < MAX2; j++) {
            if (k < 12) {
                int randIndex = rand() % (12 - k) + k;
                char temp = cartas[k];
                cartas[k] = cartas[randIndex];
                cartas[randIndex] = temp;
                tabuleiro2[i][j] = cartas[k++];
            }
        }
    }
}

void pedeCoordenadas(int *x, int *y) {
    do {
        printf("Digite a linha (1 a %d): ", MAX1 - 1);
        scanf("%d", x);
        
        if (*x < 1 || *x >= MAX1){
        	printf("\nOpcao INVALIDA! \n\n");
		}
        
    } while (*x < 1 || *x >= MAX1);
    

    do {
        printf("Digite a coluna (1 a %d): ", MAX2 - 1);
        scanf("%d", y);
        
        if  (*y < 1 || *y >= MAX2){
        	printf("\nOpcao INVALIDA! \n\n");
		}
        
    } while (*y < 1 || *y >= MAX2);
    
}
