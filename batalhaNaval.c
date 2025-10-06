#include <stdio.h>



int main() {

    //Declara a matriz 10x10 para
    int tabuleiro[10][10];
    int linha, coluna;

    // 1 Representação do tabuleiro 
    for (linha = 0; linha < 10; linha++){
        for (coluna = 0; coluna < 10; coluna++)
        tabuleiro[linha][coluna]=0;
    }

    //2. Posicionamento dos navios
    //Navio 1
    int navioH_linha = 2;
    int navioH_coluna_inicial = 3;
    if (navioH_coluna_inicial + 3 <=10){
        for (coluna = navioH_coluna_inicial; coluna < navioH_coluna_inicial + 3; coluna++){
            tabuleiro[navioH_linha][coluna] = 3;
        }
    }

    //Navio 2
    int navioV_coluna = 7;
    int navioV_linha_inicial = 5;
    if( navioV_linha_inicial + 3 <=10){
        for (linha = navioV_linha_inicial; linha < navioV_linha_inicial + 3; linha++){
            if(tabuleiro[linha][navioV_coluna] == 3){
                break;
            }
            tabuleiro[linha][navioV_coluna] = 3;
        }
    }

    //Exibindo o tabuleiro

    printf("Tabuleiro Batalha Naval\n");
    printf("   A B C D E F G H I J\n");

    for (linha = 0; linha < 10; linha++){
        printf("%2d ", linha + 1);

        for (coluna = 0; coluna < 10; coluna++){
            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    return 0;
}
