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

        // Condição para sair do loop
        if (strcmp(palavra, "1") == 0) {
            system ("cls");
            printf("\n------ Programa encerrado ------\n");
			break;
        }

        int tamanho = strlen(palavra);
        int i;
        
        printf("\nTamanho da palavra inserida: %i\n", tamanho);
        
        int eh_palindromo = 1; // Assume que é um palíndromo
        for (i = 0; i < tamanho / 2; i++) { 
            if (palavra[i] != palavra[tamanho - i - 1]) {
                eh_palindromo = 0; // Não é um palíndromo
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

