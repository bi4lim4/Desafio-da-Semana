#include <stdio.h>
//Desafio da semana #003 - Iniciante
int main(){
	
	char palavra[20];
	int contVogais = 0, contConsoantes = 0;

	printf("Digite uma palavra: ");
	scanf(" %s", &palavra);
	
	int i;
	char letra;
	
	for (i = 0; palavra[i] != '\0'; i++){
		letra = palavra[i];
		
		if (letra == 'a' || letra == 'A' 
			|| letra == 'e' || letra == 'E'
			|| letra == 'i' || letra == 'I'
			|| letra == 'o' || letra == 'O'
			|| letra == 'u' || letra == 'U') {
			
			contVogais++;	
		} else {contConsoantes++;}
	}
		
	printf("\n=================================\n");
	printf("A palavra '%s' possui: ", palavra);
	printf("\nVogais - %i", contVogais);
	printf("\nConsonantes - %i", contConsoantes);	
	
	
return 0;	
}
