//Função que converte Decimal para Binário
void decimalBinario(){
	int binario[32];
	int i = 0, j, numeroDecimal;
    
    printf("\n ===============================");
    printf("\n Digite um numero decimal: ");
    scanf("%d", &numeroDecimal);
	
	//caso alguem digite numeros negativos
	if (numeroDecimal < 0){
		printf("\n Numeros negativos NAO sao validos!!");
		return;
	}
	
	//converte binario para decimal
	while(numeroDecimal > 0){
		binario[i] = numeroDecimal % 2;
		numeroDecimal = numeroDecimal/2;
		i++;
	}
	//imprime o resultado em ordem inversa
	printf(" O numero em binario eh: ");
	for (j = i-1; j>=0; j--){
		printf("%d", binario[j]);
	}
	printf("\n ===============================\n");
	
}

//função para converter binario em decimal
void binarioDecimal() {
    int numeroDecimal = 0, i = 0, resto, numeroBinario;
    
    printf("\n ===============================");
	printf("\n Digite um numero binario: ");
    scanf("%d", &numeroBinario);
	
	while (numeroBinario != 0) {
        resto = numeroBinario % 10;
        numeroBinario /= 10;
        numeroDecimal += resto * pow(2, i);
        i++;
    }
    
    printf(" O numero em decimal eh: %d\n", numeroDecimal);
    printf(" ===============================\n");
}

//função para converter hexadecimal para Decimal
void hexaDecimal() {
    char hexa[32];

    printf("\n ===============================");
	printf("\n Digite um numero hexadecimal: ");
    scanf("%s", hexa);

    int tamanho = strlen(hexa);
    int decimal = 0, i;
    

    for (i = tamanho - 1; i >= 0; i--) {
        int digito;

        if (isdigit(hexa[i])) {
            digito = hexa[i] - '0';
        } else {
            digito = toupper(hexa[i]) - 'A' + 10;
        }

        decimal += digito * pow(16, tamanho - i - 1);
    }

    printf(" O numero em decimal eh: %d\n", decimal);
    printf(" ===============================\n");
}

//função que converte decimal em hexadecimal
void decimalHexa() {
    int decimal;

    printf("\n ===============================");
	printf("\n Digite um numero decimal: ");
    scanf("%d", &decimal);

    char hexa[32];
    int i = 0;

    while (decimal != 0) {
        int resto = 0;
        resto = decimal % 16;

        // Se o resto for menor que 10, é um dígito decimal
        if (resto < 10) {
            hexa[i] = resto + 48;
        } 
        // Caso contrário, é um dígito hexadecimal (A-F)
        else {
            hexa[i] = resto + 55;
        }

        // Atualiza o número decimal para continuar a conversão
        decimal /= 16;
        i++;
    }

    // Imprime o número hexadecimal na ordem correta (invertida)
    int j;
	printf(" O numero em hexadecimal eh: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n ===============================\n");
}

// Função para converter um número decimal em octal
void decimalOctal() {
    int decimal;
	printf("\n ===============================");
    printf("\n Digite um numero decimal: ");
    scanf("%d", &decimal);

    int octal[32], i = 0;

    // Loop para converter o número decimal em octal
    while (decimal != 0) {
        octal[i++] = decimal % 8; 
        decimal /= 8; 
    }

    // Imprime o número octal na ordem inversa
    int j;
	printf(" O numero em octal eh: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
        
    }
    printf("\n ===============================\n");
}

// Função para converter um número octal em decimal
void octalDecimal() {
    int octal;
	printf(" ===============================");
    printf("\n Digite um numero octal: ");
    scanf("%d", &octal);

    int decimal = 0, i = 0;

    // Loop para converter cada dígito octal em decimal
    while (octal != 0) {
        int digito = octal % 10; 
        decimal += digito * pow(8, i); 
        octal /= 10; 
        i++; 
    }

    printf(" O numero em decimal eh: %d\n", decimal);
    printf(" ===============================\n");
}

