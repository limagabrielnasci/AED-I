#include <stdio.h>
#include <stdbool.h>

int direcaoX[4] = {0, 1, 0, -1};
int direcaoY[4] = {1, 0, -1, 0};

bool buscaProfundidade(char** matriz, int numLinhas, int* tamanhoColunas, char* palavra, int linha, int coluna, int indice) {
    if (palavra[indice] == '\0') return true;

    if (linha < 0 || linha >= numLinhas) return false;
    if (coluna < 0 || coluna >= tamanhoColunas[linha]) return false;
    if (matriz[linha][coluna] != palavra[indice]) return false;

    char valorOriginal = matriz[linha][coluna];
    matriz[linha][coluna] = '#';

    for (int i = 0; i < 4; i++) {
        if (buscaProfundidade(matriz, numLinhas, tamanhoColunas, palavra, linha + direcaoX[i], coluna + direcaoY[i], indice + 1)) {
            matriz[linha][coluna] = valorOriginal;
            return true;
        }
    }

    matriz[linha][coluna] = valorOriginal;
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    for (int i = 0; i < boardSize; i++) 
        for (int j = 0; j < boardColSize[i]; j++) 
            if (board[i][j] == word[0] && buscaProfundidade(board, boardSize, boardColSize, word, i, j, 0))
                return true;
    return false;
}