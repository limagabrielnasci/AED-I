#include <stdio.h>
#include <stdbool.h>

bool areOccurrencesEqual(char* s) {
    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    int alvo = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            if (alvo == 0) {
                alvo = freq[i];
            } else if (freq[i] != alvo) {
                return false;
            }
        }
    }
    return true;
}