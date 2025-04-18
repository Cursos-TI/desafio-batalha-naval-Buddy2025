#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    int tabuleiro[10][10] = {0};

    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    int linha_horizontal = 2;
    int coluna_horizontal = 1;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Posicionamento horizontal
    if (coluna_horizontal + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }
    }

    // Verificação de sobreposição e posicionamento vertical
    int sobreposicao = 0;
    if (linha_vertical + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        }
    }

    // Exibição do tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    int navio_diagonal1[3] = {3, 3, 3};
    int navio_diagonal2[3] = {3, 3, 3};

    int linha_diag1 = 0;
    int coluna_diag1 = 0;

    int linha_diag2 = 9;
    int coluna_diag2 = 7;

    // Posicionamento diagonal principal (↘)
    if (linha_diag1 + 3 <= 10 && coluna_diag1 + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_diag1 + i][coluna_diag1 + i] == 0) {
                tabuleiro[linha_diag1 + i][coluna_diag1 + i] = navio_diagonal1[i];
            }
        }
    }

    // Posicionamento diagonal secundária (↙)
    if (linha_diag2 - 2 >= 0 && coluna_diag2 + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_diag2 - i][coluna_diag2 + i] == 0) {
                tabuleiro[linha_diag2 - i][coluna_diag2 + i] = navio_diagonal2[i];
            }
        }
    }

    // Exibição atualizada do tabuleiro após os 4 navios (2 horizontais/verticais e 2 diagonais)
    printf("\nTabuleiro com 4 navios (incluindo diagonais):\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
