#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "funcaoMemoria.h"
/*
		Rápida explicação do funcionamento do programa:
| Os pares são formados por letras, são 6 pares que vão de A a F		|
| a cada rodada o usuario escolhe uma linha e uma coluna para a			| 
| primeira parte do par e então outra linha e outra coluna para			|
| a outra parte do par, essa escolha se repete até o usuário finalmente	|
| acertar todos os pares.*/
int main() {
    int x1, y1, x2, y2;
    int acertos = 0;

    printf("\n\t====== JOGO DA MEMORIA! ======\n");
	
	iniciaTabuleiro();
    embaralhaCartas();

    while (acertos < 6) {
        imprimeTabuleiro();

        printf("Escolha a primeira carta:\n");
        pedeCoordenadas(&x1, &y1);
        tabuleiro1[x1][y1] = tabuleiro2[x1][y1];
        system("cls");
        imprimeTabuleiro();

        printf("Escolha a segunda carta:\n");
        pedeCoordenadas(&x2, &y2);
        tabuleiro1[x2][y2] = tabuleiro2[x2][y2];
        system("cls");
        imprimeTabuleiro();

        if (tabuleiro1[x1][y1] == tabuleiro1[x2][y2]) {
            printf("Parabens! Voce encontrou um par.\n");
            acertos++;
            Sleep(3000);
            system("cls");
        } else {
            printf("Nao eh um par! Tente novamente.\n");
            Sleep(3000);
            system("cls");
            tabuleiro1[x1][y1] = VAZIO;
            tabuleiro1[x2][y2] = VAZIO;
        }
    }

    printf("Parabens! Voce encontrou TODOS os pares.\n");
return 0;
}

