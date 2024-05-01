#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "jogoFuncoes.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main() {
    
	char casas[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'}, 
                        {'7', '8', '9'}};
    char resposta;
    int contJogadas, linha, coluna, vez = 0, i, j;
    srand(time(NULL));
    
    do {
        contJogadas = 1;
        for (i = 0; i <= 2; i++) {
            for (j = 0; j <= 2; j++) {
                casas[i][j] = ' ';
            }
        }
        do {
            exibirTabuleiro(casas);    
            if (vez % 2 == 0) {
                printf("\n Jogador X\n");
                printf("\n Digite a linha: ");
                scanf("%i", &linha);
                printf(" Digite a coluna: ");
                scanf("%i", &coluna);
                linha--;
                coluna--;
                //caso o usuário digite valores não correspondentes a linhas e colunas
                if (linha < 0 || coluna < 0 || linha > 2 || coluna > 2 || casas[linha][coluna] != ' ') {
                    printf("\n Jogada INVALIDA! Tente novamente...\n");
                    #ifdef _WIN32
					Sleep(1500);
					#else
                	usleep(1500000);
                	#endif
                    continue;
                }
                casas[linha][coluna] = 'X';
            } else {
                printf("\n Computador (O)\n");
                jogadaComputador(casas);
                // Adicionando pausa para indicar que o computador está fazendo sua jogada
                #ifdef _WIN32
                printf("\n O computador fara a jogada!");
				Sleep(1500); // Pausa de 1 segundo (1500 milissegundos) em sistemas Windows
                printf("...");
                Sleep(1000);
				#else
                usleep(1500000); // Pausa de 1 segundo (1500000 microssegundos) em sistemas Unix-like
                printf("...");
                Sleep(1000);
                #endif
            }
            vez++;
            contJogadas++;

            if (verificarVencedor(casas, 'X')) {
                contJogadas = 11;
            } else if (verificarVencedor(casas, 'O')) {
                contJogadas = 12;
            } else if (verificarEmpate(casas)) {
                contJogadas = 10;
            }
        } while (contJogadas <= 9);
        exibirTabuleiro(casas);
        
        if (contJogadas == 10) {
            printf("\n\t\t==============");
			printf("\n\t\tJogo EMPATADO!");
			printf("\n\t\t==============\n");
        } else if (contJogadas == 11) {
        	printf("\n\t   ========================");
        	printf("\n\t   Parabens! Voce venceu!!");
            printf("\n\t          Jogador 'X'");
            printf("\n\t   ========================\n");
        } else if (contJogadas == 12) {
        	printf("\n\t=============================");
            printf("\n\tO Vencedor eh o (Computador)!");
            printf("\n\t         Jogador 'O'");
            printf("\n\t=============================\n");
        }
        printf("\n Deseja jogar novamente? [S-N]: ");
        scanf(" %c", &resposta);

    } while (resposta == 's' || resposta == 'S');                    
    
return 0;   
}


