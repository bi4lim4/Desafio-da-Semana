#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include "Funcoes.h"

int main(){
		
    int opcao;
    printf("\n\t\t|==== PROGRAMA DE CONVERSAO DE BASES ====|\n");
	
	while(opcao != 7){
		printf("\n Abaixo estao os numeros correspondentes a cada conversao:");
		printf("\n 1 - Decimal para Binario");
		printf("\n 2 - Binario para Decimal");
		printf("\n 3 - Hexadecimal para Decimal");
		printf("\n 4 - Decimal para Hexadecimal");
		printf("\n 5 - Decimal para Octal");
		printf("\n 6 - Octal para Decimal");
		printf("\n 7 - Sair do programa");
		
		printf("\n Digite o numero da opcao desejada (de 1 a 7): ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				system("cls");
				decimalBinario();
				break;
	
			case 2:
				system("cls");
				binarioDecimal();
				break;
			
			case 3:
				system("cls");
				hexaDecimal();
				break;
			case 4:
				system("cls");
				decimalHexa();
				break;
			case 5:
				system("cls");
				decimalOctal();
				break;
				
			case 6:
				system("cls");
				octalDecimal();
				break;
			case 7:
				system("cls");
				break;
				
			default:
				printf("\n\t\tOpcao INVALIDA!! ");
				Sleep(1500); printf("..."); Sleep(750); printf("..."); Sleep(750);	
				system("cls");		
		}
			
	}

}
