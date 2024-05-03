#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "batle.h"
#include "funcoesBatle.h"

/* variveis globais, constantes e defini��es */

/*
Dire��o Horizontal = 1
Dire��o Vertical = 0
*/
/*
Barcos:

2x Submarino: ###

2x Encoura�ado: ####

2x Cruzador: #####

1x Porta-Avi�es: ######
                 ######
*/

int main () {
    FILE* arquivoRanking = NULL;

    arquivoRanking = fopen("ranking.txt", "a");

    if (arquivoRanking == NULL) {
        printf("Nao foi possivel abrir o arquivo de ranking!\n");
    }
    else {
        fclose(arquivoRanking);
        menuPrincipal();
    }

    return 0;
}
