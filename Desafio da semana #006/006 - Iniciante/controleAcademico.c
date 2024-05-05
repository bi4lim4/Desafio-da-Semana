#include <stdio.h>

int main(){
	
	
	int diasLetivos = 100, faltas, contAlunos = 0, contReprovadoFalta = 0, contReprovadoMedia = 0; 
	float nota, maiorNota = -1, menorNota = 10, totalNotas = 0, porcentagem;
	
	printf("\n\t ----- PROGRAMA DE CONTROLE ACADEMICO -----\n");
	printf("\n Digite a quantidade de dias letivos do periodo: ");
	scanf("%i", &diasLetivos);
	
	do {
		printf("\n ------------------------------------------------------------------\n");
		printf(" \t         OBS: digite -1 para sair\n");
		printf(" %i| Digite a nota final do aluno e o numero de faltas do mesmo: ", contAlunos+1);
		scanf("%f %i", &nota, &faltas);
		
		if (nota != -1){
            
            if (nota < 0 || nota > 10) {
                printf("\nNota INVALIDA! por favor, digite novamente\n");
                continue;
            }
            
            if (nota > maiorNota)
				maiorNota = nota;
			if (nota < menorNota)
				menorNota = nota;
								  
			totalNotas += nota; //totalNotas = totalNotas + notas
		
			if ( faltas > 0.25*diasLetivos ){
				printf("\n %i| Conceito: SFR - Reprovado por falta!", contAlunos+1);
				contReprovadoFalta++;
			} else if(nota < 5){
				printf("\n %i| Conceito: INS - Insuficiente!", contAlunos+1);
				contReprovadoMedia++;
			} else if (nota < 7){
				printf("\n %i| Conceito: REG - REgular", contAlunos+1);
			} else if (nota < 9){
				printf("\n %i| Conceito: BOM", contAlunos+1);
			} else {
				printf("\n %i| Conceito: EXC - Excelente!", contAlunos+1);
			}
		
			contAlunos++;    
		}
	}while (nota != -1);
	
	system("cls");
	int opcao; 
	do {
		printf("\n\t\tMENU");
		printf("\n 1 - Imprimir o total de alunos lidos");
		printf("\n 2 - Imprimir a maior nota da turma");
		printf("\n 3 - Imprimir a menor nota da turma");
		printf("\n 4 - Imprimir a media das notas da turma");
		printf("\n 5 - Imprimir a porcentagem de alunos reprovados por falta");
		printf("\n 6 - Imprimir a porcentagem de alunos reprovados por media");
		printf("\n 7 - Encerrar o programa");
		
		printf("\n\n Digite o numero correspondente a opcao desejada: ");
		scanf("%i", &opcao);
		system("cls");
		
		switch(opcao){
			case 1:
				printf("\n -----------------------------------------\n");
				printf("        Total de alunos lidos: %i", contAlunos);
				printf("\n -----------------------------------------\n");
				break;
				
			case 2: 
				printf("\n ------------------------------------\n");
				printf("          Maior nota: %.2f", maiorNota);
				printf("\n ------------------------------------\n");
				break;
				
			case 3:
				printf("\n ------------------------------------\n");
				printf("          Menor nota: %.2f", menorNota);
				printf("\n ------------------------------------\n");
				break;
				
			case 4:
				printf("\n ------------------------------------\n");
				printf("          Media: %.2f", totalNotas/contAlunos);
				printf("\n ------------------------------------\n");
				break;
				
			case 5:
				porcentagem = (contReprovadoFalta*100)/contAlunos;
				printf("\n ------------------------------------------------------\n");
				printf("  Porcentagem de alunos reporovados por falta: %%%.2f", porcentagem);
				printf("\n ------------------------------------------------------\n");
				break;
				
			case 6:
				porcentagem = (contReprovadoMedia*100)/contAlunos;
				printf("\n ------------------------------------------------------\n");
				printf("  Porcentagem de alunos reporovados por media: %%%.2f", porcentagem);
				printf("\n ------------------------------------------------------\n");
				break;
				
			case 7:
				printf("\n\t\t--- Programa Finalizado ---\n");
				break;						
		}
		
	} while(opcao != 7);
	
	
return 0;	
}
