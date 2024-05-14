#include <stdio.h>
#include <stdlib.h> // para a rand
#include <time.h> //para a função time

//Função para gerar o numero aleatório 
void gerandoNumeroAleatorio (int opcao);

int main(){
	
	int opcao, quantidade, numeroAleatorio;
	
	printf("\n\t\t ---- LANCADOR DE DADOS ----");
	
	srand(time(NULL)); //inicializa o gerador de numeros aleatorios
	
	do {
		printf("\n\n\t\t==== TIPOS DE DADOS ====\n");
		printf("\t\t  2  - Moeda - 2 lados\n");
		printf("\t\t  6  - Dado de 6 lados\n");
		printf("\t\t  8  - Dado de 8 lados\n");
		printf("\t\t  12 - Dado de 12 lados\n");
		printf("\t\t  20 - Dado de 20 lados\n");
		printf("\t\t  0  - Sair do Programa\n");
		printf("\t\t========================\n");
		
		printf("\nEscolha a quantidade de lados do dado: ");
		scanf("%i", &opcao);
		system("cls");
		
		int i;
		switch(opcao){
			case 2:
				
				printf("\nQuantas moedas deseja jogar?: ");
				scanf("%i", &quantidade);
				
				for (i = 0; i < quantidade; i++){
					if ( (rand()%2)+1 == 1){
						printf("\n%i| Voce tirou Cara", i+1);
					} else {
						printf("\n%i| Voce tirou Coroa", i+1);
					}				
				}
				break;
			case 6:
				gerandoNumeroAleatorio(opcao);
				break;
			case 8:
				
				gerandoNumeroAleatorio(opcao);
				break;
			case 12:
				
				gerandoNumeroAleatorio(opcao);
				break;
			case 20:
				
				printf("\nQuantos dados deseja jogar?: ");
				scanf("%i", &quantidade);
				
				for (i = 0; i < quantidade; i++){
					numeroAleatorio = (rand()%20)+1;
					
					if ( numeroAleatorio >=18 && numeroAleatorio <= 20 ){
						printf("\n%i| Parece que a sorte esta a seu favor! Voce tirou o numero: %i", 
						i+1, numeroAleatorio);
					} else {
						printf("\n%i| Voce tirou o numero: %i", i+1, numeroAleatorio);	
					}	
				}
				break;
			case 0:
				
				printf("\n\t\t---- Programa encerrado ----\n");
				break;
			default:
				printf("\n\t\t ---- Opcao INVALIDA! ----\n");			
		}
					
	} while (opcao != 0);
		
return 0;	
}
/*-------------------------------------------------------------------------------------------------------*/
void gerandoNumeroAleatorio (int opcao){
	int quantidade, i, numeroAleatorio;
	
	printf("\nQuantos dados deseja jogar?: ");
	scanf("%i", &quantidade);
				
				
	for (i = 0; i < quantidade; i++){
		numeroAleatorio = (rand()%opcao)+1;						
		if ( numeroAleatorio == (opcao-1) || numeroAleatorio == opcao){
			printf("\n%i| Parece que a sorte esta a seu favor! Voce tirou o numero: %i", i+1, numeroAleatorio);
		} else {
			printf("\n%i| Voce tirou o numero: %i", i+1, numeroAleatorio);	
			}			
		}
}

