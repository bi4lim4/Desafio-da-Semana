#include <stdio.h>

int main(){
	
	float valor, valorFinal;
	int escolha;
	
	do {
			printf("\n\n\t\t===================================================");
			printf("\n\t\t                FORMAS DE PAGAMENTO\n");
			printf("\n\t\t 1 - A vista [Dinheiro ou Pix]");
			printf("\n\t\t 2 - A vista no cartao de credito");
			printf("\n\t\t 3 - Parcelado no cartao, 2X sem juros");
			printf("\n\t\t 4 - Parcelado no cartao, 3X ou mais, com juros");
			printf("\n\t\t 0 - Sair do programa\n");
			printf("\t\t===================================================\n");
		
			printf("\n Digite o numero correspondente a forma de pagamento desejada: ");
			scanf("%i", &escolha);
			
			if (escolha == 0){
				system("cls");
				printf("\n\t\t ----- programa ENCERRADO -----\n");
				break;
			} else {
				printf("\n Digite o valor do produto: ");
				scanf("%f", &valor);
			
				system("cls");
		
				switch(escolha){
					case 1:
				
						valorFinal = valor*0.85;
						printf("\n Valor final do produto: R$ %.2f", valorFinal);
						break;
					case 2:
				
						valorFinal = valor*0.90;
						printf("\n Valor final do produto: R$ %.2f", valorFinal);
						break;
					case 3:
						valorFinal = valor;
						printf("\n Valor final do produto: R$ %.2f", valorFinal);
						break;
					case 4:
				
						valorFinal = valor*1.1;
						printf("\n Valor final do produto: R$ %.2f", valorFinal);
						break;
					case 0:
						break;
				
					default:
						printf("\n\t\t     ----- Forma de pagamento INVALIDA! -----\n");	
				}
			}
					
	}while (escolha != 0);
	
return 0;	
} 
 
