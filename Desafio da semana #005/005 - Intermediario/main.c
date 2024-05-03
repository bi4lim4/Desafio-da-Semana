#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "batle.h"
#include "funcoesBatle.h"

/* variveis globais, constantes e definições */

/*
Direção Horizontal = 1
Direção Vertical = 0
*/
/*
Barcos:

2x Submarino: ###

2x Encouraçado: ####

2x Cruzador: #####

1x Porta-Aviões: ######
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
