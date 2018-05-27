//
// Created by igor on 27.05.18.
//
#include "enter.h"
char* enter (int n, const char input[]) {
    char *res = (char*) malloc(sizeof(char) * (strlen(input) + strlen(input) / n));
    unsigned int counter = 0;
    unsigned int pos = 0;
    for (int i = 0; i < strlen(input); i++) {
        counter++;
        res[pos] = input[i];
        pos++;
        if (counter == n) {
            res[pos] = '\n';
            pos++;
            counter=0;
        }
    }
    return res;
}
int main() {
    return 0;
}

