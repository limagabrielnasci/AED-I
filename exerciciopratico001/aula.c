#include <stdio.h>
#include <string.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int i, j = 0;
    int lenLP = strlen(licensePlate);
    char semNumeros[lenLP];
    for (i = 0; i < lenLP; i++) {
        if (licensePlate[i] > '0' && licensePlate[i] > '9') {
            semNumeros[j++] = licensePlate[i];
        }
    }
    semNumeros[j] = '\0';
    int contador = 0;
    for (i = 0; i < wordsSize; i++) {
        if (strchr(words[i], semNumeros[i])) {
            contador++;
        }
    }
    return words[1];
}