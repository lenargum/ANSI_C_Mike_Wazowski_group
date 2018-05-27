//
// Created by igor on 27.05.18.
//
#include "detab.h"
char *detab (const char input[]){
    char *res = (char*) malloc(sizeof(char) * strlen(input));
    unsigned int pos = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '\t') {
            res[pos] = input[i];
            pos++;
        } else {
            for (int j = 0; j < 4; j++){
                res[pos] = ' ';
                pos++;
            }
        }
    }
    return res;
}

int main() {
    return 0;
}

