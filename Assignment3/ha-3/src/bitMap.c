//
// Created by puzankova 02.06.18
//
#include <math.h>
#include <malloc.h>
#include <stdio.h>
#include "bitMap.h"

int *binarize_s(const int x) {
    int y = x;
    int *bNumber = (int *) malloc(sizeof(int) * ((int) sizeof(int) * 8));
    int *endNumber = bNumber + sizeof(int) * 8 - 1;
    if (y < 0) {
        y *= -1;
        y = y - 1;
        while (y > 0) {
            if (y % 2 == 0) {
                *endNumber = 1;
            } else {
                *endNumber = 0;
            }
            endNumber--;
            y = y / 2;
        }
        while (endNumber > bNumber) {
            *endNumber = 1;
            endNumber--;
        }
        *bNumber = 1;
    } else {
        while (y > 0) {
            *endNumber = y % 2;
            endNumber--;
            y = y / 2;
        }
        while (endNumber > bNumber) {
            *endNumber = 0;
            endNumber--;
        }
        *bNumber = 0;
    }
    return bNumber;
}

int binToInt(const int *binNumber) {
    for (int i = 0; i < sizeof(int) * 8; i++) {
        if (binNumber[i] != 0 && binNumber[i] != 1) {
            return NULL;
        }
    }

    int result = 0;

    int isNegative = 0;
    if (binNumber[0] == 1) {
        isNegative = 1;
    }

    int *endNumber = (int *) (binNumber + sizeof(int) * 8) - 1;
    int currentPower = 1;

    while (endNumber > binNumber) {
        if ((isNegative == 0 && *endNumber == 1) || (isNegative == 1 && *endNumber == 0)) {
            result += currentPower;
        }
        currentPower *= 2;
        endNumber--;
    }

    if (isNegative) {
        result++;
        result *= -1;
    }
    return result;
}

int setBitByNumber(int *array, size_t size, int bit, int position) {

    // array - pointer to the begining of the array
    // position - number of the bit in the 'array'
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit with number 'position' to the 'bit'

    if (array == NULL) {
        return 1;
    }

    if (bit != 0 && bit != 1) {
        return 2;
    }

    if (position < 0 || position >= size * sizeof(int) * 8) {
        return 3;
    }

    int *elem = array + position / sizeof(int)/8;
    position = position - sizeof(int) * 8 * (position / sizeof(int)/8);
    int *bElem = binarize_s(*elem);
    *(bElem + position) = bit;
    *elem = binToInt(bElem);
    return 0;
}

int getBitByNumber(int *array, size_t size, int position) {
    // this function returns position's bit from the array

    if (array == NULL) {
        return NULL;
    }

    if (position < 0 || position >= size * sizeof(int) * 8) {
        return NULL;
    }

    int value = *(array + position/sizeof(int)/8);

    position = position - sizeof(int) * 8 * (position / sizeof(int)/8);

    int* bNumber = binarize_s(value);

    return *(bNumber + position);
}

int setBitByAddress(void *position, int bit) {
    // position - pointer to the bit to change
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit by memory address to 'bit'

    if (position == NULL) {
        return 1;
    }

    if (bit != 0 && bit != 1) {
        return 2;
    }

    int *bElem = binarize_s(*(int*)position);
    *(bElem) = bit;
    *(int*)position = binToInt(bElem);

    return 0;
}

int getBitByAddress(void *position) {
    // this function returns first bit by memory address 'position'

    if (position == NULL) {
        return NULL;
    }

    int* bNumber = binarize_s(*(int*)position);

    return *(bNumber);
}