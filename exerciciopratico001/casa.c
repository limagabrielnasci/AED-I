#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

/*
===============================================================================
    
    Given a string licensePlate and an array of strings words, find the shortest completing word in words.

    A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.

    For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".

    Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.

===============================================================================
*/

char* ShortestCompletingWord( char* licensePlate, char** words, int wordsSize ) {
    // armazena a frequência de cada letra
    // inicializa com zeros
    int freq[26] =  { 0 };
    int i, j;

    /*
    ====================
    frequência de letras
    ====================
    */
    // cada indice do vetor freq vai ser uma letra (a-z)
    // vai conter a quantidade de vezes que aparece na string
    for ( i = 0; licensePlate[i] != '\0'; i++ ) {
        if ( isalpha( licensePlate[i] ) ) {
            char c = tolower( licensePlate[i] );
            freq[c - 'a']++;
        }
    }

    char* palavraMaisCurta = NULL;
    int comprimentoMaisCurto = INT_MAX;

    /*
    ====================
    encontrar a palavra que completa mais curta
    ====================
    */
    // itera por cada palavra no vetor words
    for ( i = 0; i < wordsSize; i++ ) {
        // armazena a frequência de cada letra para a palavra atual
        int freqAtual[26] = { 0 };
        // flag pra indicar se é completa
        // assumindo como verdade até que seja provado o contrário
        int ehCompleta = 1;
        
        /*
        ====================
        frequência de letras da palavra atual
        ====================
        */
        for ( j = 0; words[i][j] != '\0'; j++ ) {
            if ( isalpha( words[i][j] ) ) {
                char c = tolower( words[i][j] );
                freqAtual[c - 'a']++; 
            }
        }

        /*
        ====================
        verificando se é completa
        ====================
        */
        // compara a frequência de letras da string licensePlate (freq)
        // com as frequências na palavra atual (freqAtual)
        // se a palavra atual tiver menos de alguma letra necessária ela não é uma palavra que completa
        for ( j = 0; j < 26; j++ ) {
            if ( freq[j] > freqAtual[j] ) {
                ehCompleta = 0;
                break;
            }
        }

        /*
        ====================
        atualiza a palavra que completa mais curta
        ====================
        */
        // se a palavra atual é uma palavra que completa e seu comprimento é mais curto
        // do que a mais curta encontrada até agora, atualiza a palavra mais curta e seu comprimento.
        if ( ehCompleta && strlen( words[i] ) < comprimentoMaisCurto ) {
            comprimentoMaisCurto = strlen( words[i] );
            palavraMaisCurta = words[i];
        }
    }

    return palavraMaisCurta;
}