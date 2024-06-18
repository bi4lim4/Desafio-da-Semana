#include <stdio.h>
#include <windows.h>
int main(){
	
	int contAluno = 0;
	float nota1[10], nota2[10], media[10];
	
	do {
		
		printf("\n---------- Aluno %i ----------\n", contAluno+1);
		printf("Digite a primeira nota: ");
		scanf("%f", &nota1[contAluno]);
		
		printf("Digite a segunda nota: ");
		scanf("%f", &nota2[contAluno]);
		
		if (nota2[contAluno] < 0 || nota2[contAluno] > 10 || nota1[contAluno] < 0 || nota1[contAluno] > 10) {
            printf("\nNota INVALIDA! por favor, digite novamente\n");
            continue;    
    	}
		
		media[contAluno] = ((nota1[contAluno] * 4) + (nota2[contAluno]*6))/10;
		
		printf("\nMedia do aluno: %.2f", media[contAluno]);
		
		if (media[contAluno] < 5){
			printf("\nConceito: INSUFICIENTE");
			printf("\nReprovado!\n");
		} else if (media[contAluno] < 7){
			printf("\nConceito: REGULAR");
			printf("\nAprovado!\n");
		} else if (media[contAluno] < 9){
			printf("\nConceito: BOM");
			printf("\nAprovado!\n");
		} else {
			printf("\nConceito: EXCELENTE");
			printf("\nAprovado!\n");
		}
		
		contAluno++;
	} while (contAluno < 10);
	
	printf("\n..."); Sleep(750);printf("..."); Sleep(750);printf("..."); Sleep(750);
	system("cls");
	int i;
	printf("\n\nMedia de todos os alunos:\n");
	for(i = 0; i < 10; i++){
		printf("\nAluno %i: %.2f", i+1, media[i]);
	}
	
	
return 0;	
}
