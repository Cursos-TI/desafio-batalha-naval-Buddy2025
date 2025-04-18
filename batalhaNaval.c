#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAMANHO_TABULEIRO 10

int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Matriz do tabuleiro

// Função para exibir o tabuleiro
void exibir_tabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Nível Mestre - Habilidades Especiais com Matrizes

void aplicar_habilidade_cone(int x, int y) {
    if (x >= 0 && x + 2 < TAMANHO_TABULEIRO && y - 2 >= 0 && y + 2 < TAMANHO_TABULEIRO) {
        tabuleiro[x][y] = 1;
        tabuleiro[x + 1][y] = 1;
        tabuleiro[x + 1][y - 1] = 1;
        tabuleiro[x + 1][y + 1] = 1;
        tabuleiro[x + 2][y] = 1;
        tabuleiro[x + 2][y - 1] = 1;
        tabuleiro[x + 2][y + 1] = 1;
        tabuleiro[x + 2][y - 2] = 1;
        tabuleiro[x + 2][y + 2] = 1;
    }
}

void aplicar_habilidade_octaedro(int x, int y) {
    if (x - 1 >= 0 && x + 1 < TAMANHO_TABULEIRO && y - 1 >= 0 && y + 1 < TAMANHO_TABULEIRO) {
        tabuleiro[x][y] = 1;
        tabuleiro[x - 1][y] = 1;
        tabuleiro[x + 1][y] = 1;
        tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y + 1] = 1;
        tabuleiro[x - 1][y - 1] = 1;
        tabuleiro[x - 1][y + 1] = 1;
        tabuleiro[x + 1][y - 1] = 1;
        tabuleiro[x + 1][y + 1] = 1;
    }
}

void aplicar_habilidade_cruz(int x, int y) {
    if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
        tabuleiro[x][y] = 1;
        if (x - 1 >= 0) tabuleiro[x - 1][y] = 1;
        if (x + 1 < TAMANHO_TABULEIRO) tabuleiro[x + 1][y] = 1;
        if (y - 1 >= 0) tabuleiro[x][y - 1] = 1;
        if (y + 1 < TAMANHO_TABULEIRO) tabuleiro[x][y + 1] = 1;
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
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

    // Aplicação das habilidades especiais
    aplicar_habilidade_cone(2, 6);
    aplicar_habilidade_octaedro(7, 3);
    aplicar_habilidade_cruz(5, 5);

    // Exibição do tabuleiro atualizado
    printf("\nTabuleiro com habilidades aplicadas:\n");
    exibir_tabuleiro();

    return 0;
}
