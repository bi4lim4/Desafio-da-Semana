#define MAX 15

void limpaTela(void);
void limpaBuffer(void);
void iniciaTabuleiro(void);
void imprimeOpcoesDeBarcos(void);
void imprimeTabuleiro();
int haBarcos(int barco, char M[MAX][MAX]);
void colheDados(char M[MAX][MAX]);
void colheDadosCpu(char M[MAX][MAX]);
int verificaJogada(int linha, int coluna, char M[MAX][MAX]);
int atira(int linha, int coluna, char M[MAX][MAX]);
void verificaFimDeJogo();
void turnoDoJogador();
void turnoDaCpu();
void rodadas();
void escreveNoRanking();
void organizarRanking();
void mostrarRanking();
void fimDeJogo();
void novoJogo();
void guia_Jogo();
void reset();
void executaOpcao(char opcao);
void menuPrincipal();
void menuPrincipal_1();
int verificaBarcos(int barco, int direcao, int linha, int coluna, char M[MAX][MAX]);
void imprimeBarcos(int barco, int direcao, int linha, int coluna, char M[MAX][MAX]);

int verificaSubmarino(int direcao, int linha, int coluna, char M[MAX][MAX]);
void imprimeSubmarino(int direcao, int linha, int coluna, char M[MAX][MAX]);
int verificaCruzadores(int direcao, int linha, int coluna, char M[MAX][MAX]);
void imprimeCruzadores(int direcao, int linha, int coluna, char M[MAX][MAX]);
int verificaEncouracados(int direcao, int linha, int coluna, char M[MAX][MAX]);
void imprimeEncouracados(int direcao, int linha, int coluna, char M[MAX][MAX]);
int verificaPortaAvioes(int direcao, int linha, int coluna, char M[MAX][MAX]);
void imprimePortaAvioes(int direcao, int linha, int coluna, char M[MAX][MAX]);
