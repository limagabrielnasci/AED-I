#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int *resultado = malloc(wordsSize * sizeof(int));
    int contador = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (strchr(words[i], x)) {
            resultado[contador++] = i;
        }
    }
    *returnSize = contador;
    return resultado;
}