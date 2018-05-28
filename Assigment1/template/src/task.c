//
// Created by cubazis on 25.05.18.
//

#include <string.h>
#include "task.h"

/** The stub function
 *  just to demonstrate how to work with ck_assert
 *  please look for test case for stub function in test_task.c
 */

int stub(void)
{
	return 42;
}

/** The array_changer function
 *  just to demonstrate how to work with returning of array from function
 *
 *  1) C language doesn't have strings
 *  2) array in a C language is just a segment of memory
 *  3) C lang doesn't have ability to pass array as parameter in a function
 *  4) we suppose that you don't know about memory allocation through pointers
 *
 *  so, we provide you simple demo function which change 'c' char in input array
 *  	input parameter: constant array of chars
 *  	output: pointer to memory segment in which resulting array starts
 *
 *  	extra stuff: we provide you three define macros in task.h.
 *  		you can use them in your solutions
 *  		if you don't want to use them please, don't delete them - somebody may use it
 *
 *  please look for test case for array_changer function in test_task.c
 */

char* array_changer(const char c[])
{
	char j = 0;
	int size = 0;
	STRING_LEN(size, c);
	char* b = ALLOCATE(size);

	for (;j < size;) {
		if(c[j] == 'c')
			b[j] = 'b';
		else
			b[j] = c[j];
		j++;
	}
	return b;
}

/** YOUR SOLUTIONS */

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
    res[pos] = '\0';
    return res;
}

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
    res[pos] = '\0';
    return res;
}

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
    res[pos] = '\0';
    return res;
}

char *flush(const char input[]) {
    char *result = malloc(sizeof(input));
    char isComment = 'n';
    int resultLastIndex = 0;

    for (int i = 0; i < strlen(input); i++) {
        switch (isComment) {
            case 'n':
                if (input[i] != '/') {
                    result[resultLastIndex] = input[i];
                    resultLastIndex++;
                    continue;
                } else {
                    if (i + 1 < strlen(input)) {
                        switch (input[i + 1]) {
                            case '*':
                                isComment = 'l';
                                i++;
                                break;
                            case '/':
                                isComment = 's';
                                i++;
                                break;
                            default:
                                result[resultLastIndex] = input[i];
                                resultLastIndex++;
                        }
                    }
                }
                break;
            case 'l':
                if (input[i] == '*' && i + 1 < strlen(input) && input[i + 1] == '/') {
                    isComment = 'n';
                    i++;
                }
                break;
            case 's':
                if (input[i] == '\n') {
                    isComment = 'n';
                }
                break;
        }
    }
    return result;
}

int htoi(const char hex[]) {
    int integer = 0; //result
    long long int stp16 = 1; //power of 16
    int nonZeroDigitIndex = 2; //index of first non zero digit

    //Searching for nonzero digit to save time
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        while (hex[nonZeroDigitIndex] == '0' && nonZeroDigitIndex < strlen(hex)) {
            nonZeroDigitIndex++;
        }

        //For every letter we use appropriate integer
        for (long int i = strlen(hex) - 1; i >= nonZeroDigitIndex; i--) {
            char cur = hex[i];
            if ((cur >= 65) && (cur <= 90))
                cur = (char) (cur + 32);

            switch (cur) {
                case 'f':
                    integer += 15 * stp16;
                    break;
                case 'e':
                    integer += 14 * stp16;
                    break;
                case 'd':
                    integer += 13 * stp16;
                    break;
                case 'c':
                    integer += 12 * stp16;
                    break;
                case 'b':
                    integer += 11 * stp16;
                    break;
                case 'a':
                    integer += 10 * stp16;
                    break;
                default:
                    integer += (int) cur * stp16;
                    break;
            }
            //Accumulation of power of 16
            stp16 *= 16;
        }
        return integer;
    } else {
        //short handle for irrelevant strings
        printf("Inputted number is not hexadecimal.");
        return 0;
    }
}


char *squeeze(const char s1[], const char s2[]) {
    char* result = malloc(sizeof(s1)); //allocating memory for result string
    char isContains; //is current letter contains in s2 ('f' for false and 't' for true)
    long int lastS1Index = 0; //saving last index of result string

    for (long int i = 0; i < strlen(s1); i++) {
        isContains = 'f';
        //comparison of letters from s1 and s2
        for (long int j = 0; j < strlen(s2) && isContains=='f'; j++) {
            if(s1[i]==s2[j]) {
                isContains ='t';
            }
        }
        //copying letter if s2 don't contain it
        if(isContains=='f') {
            result[lastS1Index] = s1[i];
            lastS1Index++;
        }
    }
    return result;
}

int strrindex(const char s[], const  char t[]){
    int index = -1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == t[0] && strlen(s) - i >= strlen(t) && index == -1) {
            unsigned count = 0;
            for (int j = 0; j < strlen(t); j++) {
                if (s[i+j] == t[j]) count++;
            }
            if (count == strlen(t)) index = i;
        }
    }
    return index;
}

double atofe(const char s[]){
    char* str = malloc(sizeof(s));
    int index = 0;
    for (int i =0; i < strlen(s) && s[i] != 'e'; i++){
        index = i;
        str[i] = s[i];
    }
    double d;
    sscanf(s, "%lf", &d);
    return d;
}
/** GET FROM task.h */