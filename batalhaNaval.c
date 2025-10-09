#include <stdio.h>

int main() {
    // Variáveis de configuração
    int TAMANHO_TABULEIRO = 10;
    int TAMANHO_NAVIO = 3;
    int AGUA = 0;
    int NAVIO = 3;

    int tabuleiro[10][10];
    int linha, coluna;

    // --- 1. Inicialize o Tabuleiro: Preenchendo com água ---
    printf("Inicializando o tabuleiro...\n");
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // --- 2. Posicione Quatro Navios (tamanho 3) ---
    printf("Posicionando os navios...\n");

    // --- Navio 1: Horizontal ---
    int navio1_linha = 1;
    int navio1_coluna_inicial = 1;
    int espaco_livre = 1; // 1 para 'true', 0 para 'false'

    if (navio1_coluna_inicial + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio1_linha][navio1_coluna_inicial + i] != AGUA) {
                espaco_livre = 0;
                break;
            }
        }
        if (espaco_livre) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navio1_linha][navio1_coluna_inicial + i] = NAVIO;
            }
        }
    }

    // --- Navio 2: Vertical ---
    int navio2_linha_inicial = 3;
    int navio2_coluna = 8;
    espaco_livre = 1;

    if (navio2_linha_inicial + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio2_linha_inicial + i][navio2_coluna] != AGUA) {
                espaco_livre = 0;
                break;
            }
        }
        if (espaco_livre) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navio2_linha_inicial + i][navio2_coluna] = NAVIO;
            }
        }
    }

    // --- Navio 3: Diagonal (linha e coluna aumentam) ---
    int navio3_linha_inicial = 4;
    int navio3_coluna_inicial = 1;
    espaco_livre = 1;

    if (navio3_linha_inicial + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && navio3_coluna_inicial + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio3_linha_inicial + i][navio3_coluna_inicial + i] != AGUA) {
                espaco_livre = 0;
                break;
            }
        }
        if (espaco_livre) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navio3_linha_inicial + i][navio3_coluna_inicial + i] = NAVIO;
            }
        }
    }

    // --- Navio 4: Diagonal (linha aumenta, coluna diminui) ---
    int navio4_linha_inicial = 7;
    int navio4_coluna_inicial = 4;
    espaco_livre = 1;

    if (navio4_linha_inicial + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && navio4_coluna_inicial - (TAMANHO_NAVIO - 1) >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio4_linha_inicial + i][navio4_coluna_inicial - i] != AGUA) {
                espaco_livre = 0;
                break;
            }
        }
        if (espaco_livre) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navio4_linha_inicial + i][navio4_coluna_inicial - i] = NAVIO;
            }
        }
    }

    // --- 3. Exiba o Tabuleiro ---
    printf("\n--- TABULEIRO DE BATALHA NAVAL ---\n");
    printf("   A B C D E F G H I J\n"); // << LINHA CORRIGIDA

    
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%2d ", linha + 1); 

        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}