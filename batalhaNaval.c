#include <stdio.h>

// --- Constantes para configuração do jogo ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5 

// --- Representação dos elementos no tabuleiro ---
#define AGUA 0
#define NAVIO 3
#define AREA_AFETADA 5

// --- Funções Auxiliares ---

int valorAbsoluto(int n) {
    if (n < 0) {
        return -n; 
    }
    return n; 
}


void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna);


int main() {
    // --- 1. Definição do Tabuleiro e Variáveis ---
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna;

    // --- 2. Inicialize o Tabuleiro: Preenchendo com água ---
    printf("Inicializando o tabuleiro...\n");
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // --- 3. Posicione Quatro Navios (tamanho 3) ---
    printf("Posicionando os navios...\n");
    for (int i = 0; i < 3; i++) tabuleiro[1][1 + i] = NAVIO;
    for (int i = 0; i < 3; i++) tabuleiro[3 + i][8] = NAVIO;
    for (int i = 0; i < 3; i++) tabuleiro[4 + i][1 + i] = NAVIO;
    for (int i = 0; i < 3; i++) tabuleiro[6 + i][4 - i] = NAVIO;


    // --- 4. Criar Matrizes de Habilidade (5x5) ---
    printf("Criando matrizes de habilidades...\n");

    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // --- Construção da Habilidade em Cone ---
    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            if (coluna >= (TAMANHO_HABILIDADE / 2) - linha && coluna <= (TAMANHO_HABILIDADE / 2) + linha) {
                habilidade_cone[linha][coluna] = 1;
            } else {
                habilidade_cone[linha][coluna] = 0;
            }
        }
    }

    // --- Construção da Habilidade em Cruz ---
    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            if (linha == TAMANHO_HABILIDADE / 2 || coluna == TAMANHO_HABILIDADE / 2) {
                habilidade_cruz[linha][coluna] = 1;
            } else {
                habilidade_cruz[linha][coluna] = 0;
            }
        }
    }

    // --- Construção da Habilidade em Octaedro (Forma de Losango/Diamante) ---
    int centro = TAMANHO_HABILIDADE / 2;
    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            
            if (valorAbsoluto(linha - centro) + valorAbsoluto(coluna - centro) <= centro) {
                habilidade_octaedro[linha][coluna] = 1;
            } else {
                habilidade_octaedro[linha][coluna] = 0;
            }
        }
    }

    // --- 5. Integrar Habilidades ao Tabuleiro ---
    printf("Aplicando habilidades no tabuleiro...\n");

    int cone_origem_linha = 2;
    int cone_origem_coluna = 5;
    int cruz_origem_linha = 5;
    int cruz_origem_coluna = 2;
    int octaedro_origem_linha = 7;
    int octaedro_origem_coluna = 7;

    aplicarHabilidade(tabuleiro, habilidade_cone, cone_origem_linha, cone_origem_coluna);
    aplicarHabilidade(tabuleiro, habilidade_cruz, cruz_origem_linha, cruz_origem_coluna);
    aplicarHabilidade(tabuleiro, habilidade_octaedro, octaedro_origem_linha, octaedro_origem_coluna);


    // --- 6. Exiba o Tabuleiro com Habilidade ---
    printf("\n--- TABULEIRO FINAL COM HABILIDADES ---\n");
    printf("Legenda: '~' Agua, 'N' Navio, '*' Area Afetada\n");
    printf("    A B C D E F G H I J\n");
    printf("   ---------------------\n");

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d |", linha + 1);
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            switch (tabuleiro[linha][coluna]) {
                case AGUA:
                    printf(" ~");
                    break;
                case NAVIO:
                    printf(" N");
                    break;
                case AREA_AFETADA:
                    printf(" *");
                    break;
                default:
                    printf(" ?");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}

// Implementação da função aplicarHabilidade
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna) {
    int centro_habilidade = TAMANHO_HABILIDADE / 2;
    int linha_tabuleiro, coluna_tabuleiro;

    for (int l_habilidade = 0; l_habilidade < TAMANHO_HABILIDADE; l_habilidade++) {
        for (int c_habilidade = 0; c_habilidade < TAMANHO_HABILIDADE; c_habilidade++) {
            if (habilidade[l_habilidade][c_habilidade] == 1) {
                linha_tabuleiro = origem_linha + (l_habilidade - centro_habilidade);
                coluna_tabuleiro = origem_coluna + (c_habilidade - centro_habilidade);
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = AREA_AFETADA;
                }
            }
        }
    }
}