#include <stdio.h>
#include <string.h>
#include <windows.h>
#define N 20

int main() {
    char palavra[N];
    
    while (1) {
        printf(" ----- Digite '1' para sair -----\n");
        printf("Insira uma palavra: ");
        scanf(" %s", palavra);

        // Condi��o para sair do loop
        if (strcmp(palavra, "1") == 0) {
            system ("cls");
            printf("\n------ Programa encerrado ------\n");
			break;
        }

        int tamanho = strlen(palavra);
        int i;
        
        printf("\nTamanho da palavra inserida: %i\n", tamanho);
        
        int eh_palindromo = 1; // Assume que � um pal�ndromo
        for (i = 0; i < tamanho / 2; i++) { 
            if (palavra[i] != palavra[tamanho - i - 1]) {
                eh_palindromo = 0; // N�o � um pal�ndromo
                break;
            }
        }
        
        if (eh_palindromo) {
            printf("\nA palavra inserida EH um palindromo\n\n");
        } else {
            printf("\nA palavra inserida NAO EH um palindromo\n\n");
        }
    }

    return 0;
}

