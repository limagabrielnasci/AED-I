#include <stdio.h>

void reverseString(char* s, int sSize) {
    char* s2 = malloc(sSize * sizeof(char));
    int i, j = 0;
    for (i = sSize - 1; i >= 0; i--) {
        s2[j++] = s[i];
    }
    for (i = 0; i < j; i++) {
        s[i] = s2[i];
    }
    free(s2);
}