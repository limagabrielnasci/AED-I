#include <stdio.h>
#include <stdlib.h>

char* clearDigits(char* s) {
    int j = 0, len = 0;
    while (s[len]) len++;
    char *s2 = malloc((len + 1) * sizeof(char));
    if (!s2) return NULL;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            if (j > 0) j--;
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
    return s2;
}