//funções para o jogo da velha
//Exibe o tabuleiro na tela
void exibirTabuleiro(char casas2[3][3]) {
    system("cls");
    printf("\n\t\t  %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]);
    printf("\t\t -----------\n");
    printf("\t\t  %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]);
    printf("\t\t -----------\n");
    printf("\t\t  %c | %c | %c \n", casas2[2][0], casas2[2][1], casas2[2][2]);
}
//verifica se o jogador venceu
int verificarVencedor(char casas2[3][3], char jogador) {
    if ((casas2[0][0] == jogador && casas2[0][1] == jogador && casas2[0][2] == jogador) ||
        (casas2[1][0] == jogador && casas2[1][1] == jogador && casas2[1][2] == jogador) ||
        (casas2[2][0] == jogador && casas2[2][1] == jogador && casas2[2][2] == jogador) ||
        (casas2[0][0] == jogador && casas2[1][0] == jogador && casas2[2][0] == jogador) ||
        (casas2[0][1] == jogador && casas2[1][1] == jogador && casas2[2][1] == jogador) ||
        (casas2[0][2] == jogador && casas2[1][2] == jogador && casas2[2][2] == jogador) ||
        (casas2[0][0] == jogador && casas2[1][1] == jogador && casas2[2][2] == jogador) ||
        (casas2[0][2] == jogador && casas2[1][1] == jogador && casas2[2][0] == jogador)) {
        return 1; // Se o jogador ganhar
    }
    return 0; // Se não houver vencedor
}
//verifica se ocorreu empare
int verificarEmpate(char casas2[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (casas2[i][j] == ' ') {
                return 0; // Ainda há casas vazias, o jogo não está empatado
            }
        }
    }
    return 1; // Se não há casas vazias, é um empate
}

//Faz a jogada do computador
void jogadaComputador(char casas2[3][3]) {
    int linha, coluna;
    char adversario = 'X'; // Representa o símbolo do jogador adversário
	int jogadasDisponiveis[9];
	int numJogadasDisponiveis = 0;

	//verifica as jogadas disponiveis
	for (linha = 0; linha < 3; linha++){
		for (coluna = 0; coluna < 3; coluna++){
			if(casas2[linha][coluna] == ' '){
				jogadasDisponiveis[numJogadasDisponiveis] = (linha*3) + coluna; 
				numJogadasDisponiveis++;
			}
		}
	}

	int i;
    // Verifica se existe uma jogada que resultaria em vitória imediata para o computador
    for (i = 0; i < numJogadasDisponiveis; i++) {
        linha = jogadasDisponiveis[i]/3;
        coluna = jogadasDisponiveis[i] % 3;
        casas2[linha][coluna] = 'O';
        if (verificarVencedor(casas2, '0')){
        	return;
		}
		casas2[linha][coluna] = ' ';
    }

     // Verifica se existe uma jogada que evita a vitória imediata do jogador adversário
    for (i = 0; i < numJogadasDisponiveis; i++) {
        linha = jogadasDisponiveis[i] / 3;
        coluna = jogadasDisponiveis[i] % 3;
        casas2[linha][coluna] = adversario;
        if (verificarVencedor(casas2, adversario)) {
            casas2[linha][coluna] = 'O'; // Bloqueia a jogada do adversário
            return;
        }
        casas2[linha][coluna] = ' '; // Desfaz a jogada
    }

    // Escolhe uma jogada aleatória entre as disponíveis
    int indexJogada;
	indexJogada = rand() % numJogadasDisponiveis;
    linha = jogadasDisponiveis[indexJogada] / 3;
    coluna = jogadasDisponiveis[indexJogada] % 3;
    casas2[linha][coluna] = 'O';
}

