//
// Created by igor on 27.05.18.
//
#include "entab.h"
char *entab (const char input[]){
    char *res = (char*) malloc(sizeof(input));
    unsigned int pos = 0;
    int i = 0;
    while (i < strlen(input)) {
        if (input[i] != ' ') {
            res[pos] = input[i];
            pos++;
        } else {
            int space_counter = 0;
            for (int j = i; j < i + 4 && i + 4 < strlen(input); j ++){
                if (input[j] == ' ') space_counter++;
            }
            if (space_counter == 4) {
                res[pos] = '\t';
                i += 3;
                pos ++;
            } else {
                res[pos] = ' ';
                pos ++;
            }
        }
        i++;
    }
    return res;
}
int main() {
    return 0;
}