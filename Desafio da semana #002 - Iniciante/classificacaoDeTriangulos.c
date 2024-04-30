#include <stdio.h>

int main(){
	
	float ladoA, ladoB, ladoC;
	
	printf("\n\t ========= DESAFIO 02 - CLASSIFICACAO DE TRIANGULOS =========\n\n");
	
	printf(" Digite o comprimento do lado A do triangulo: ");
	scanf("%f", &ladoA);
	
	printf(" Digite o comprimento do lado B do triangulo: ");
	scanf("%f", &ladoB);
	
	printf(" Digite o comprimento do lado C do triangulo: ");
	scanf("%f", &ladoC);
	
	
	if ((ladoA + ladoB) < ladoC || (ladoA + ladoC) <  ladoB || (ladoB + ladoC) < ladoA){
		printf("\n O triangulo eh invalido!");
	}else if(ladoA == ladoB && ladoB == ladoC){
		printf("\n O triangulo eh equilatero");
	} else if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC){
		printf("\n O triangulo eh isosceles");
	} else {
		printf("\n O triangulo eh escaleno");
	}  	
	
return 0;	
}