#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade

// Função para inicializar o tabuleiro com valores de água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Inicializa com 0 (água)
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 "); // Área de efeito da habilidade
            }
        }
        printf("\n");
    }
}

// Função para posicionar navios horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // Marca o navio com 3
    }
}

// Função para posicionar navios verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // Marca o navio com 3
    }
}

// Função para criar a matriz de habilidade em forma de cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {{0, 0, 1, 0, 0},
                                                        {0, 1, 1, 1, 0},
                                                        {1, 1, 1, 1, 1},
                                                        {0, 1, 1, 1, 0},
                                                        {0, 0, 1, 0, 0}};

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                int x = linha + i - TAMANHO_HABILIDADE / 2;
                int y = coluna + j - TAMANHO_HABILIDADE / 2;
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    tabuleiro[x][y] = 5; // Marca a área afetada pela habilidade (valor 5)
                }
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {{0, 0, 1, 0, 0},
                                                        {0, 1, 1, 1, 0},
                                                        {1, 1, 1, 1, 1},
                                                        {0, 1, 1, 1, 0},
                                                        {0, 0, 1, 0, 0}};

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                int x = linha + i - TAMANHO_HABILIDADE / 2;
                int y = coluna + j - TAMANHO_HABILIDADE / 2;
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    tabuleiro[x][y] = 5; // Marca a área afetada pela habilidade (valor 5)
                }
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {{0, 0, 1, 0, 0},
                                                            {0, 1, 1, 1, 0},
                                                            {1, 1, 1, 1, 1},
                                                            {0, 1, 1, 1, 0},
                                                            {0, 0, 1, 0, 0}};

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                int x = linha + i - TAMANHO_HABILIDADE / 2;
                int y = coluna + j - TAMANHO_HABILIDADE / 2;
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    tabuleiro[x][y] = 5; // Marca a área afetada pela habilidade (valor 5)
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios no tabuleiro
    posicionarNavioHorizontal(tabuleiro, 2, 3);
    posicionarNavioVertical(tabuleiro, 5, 6);

    // Aplica as habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, 5, 5);       // Cone com origem em (5, 5)
    aplicarHabilidadeCruz(tabuleiro, 3, 3);       // Cruz com origem em (3, 3)
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);   // Octaedro com origem em (7, 7)

    // Exibe o tabuleiro final
    printf("Tabuleiro Final com Habilidades:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
