//
// Created by artem on 02.06.2018.
//

#ifndef __BITMAP_H_
#define __BITMAP_H_

int setBitByNumber(int* array, size_t size, int bit, int position);

int getBitByNumber(int* array, size_t size, int position);

int setBitByAddress(void* position, int bit);

int getBitByAddress(void* position);

#endif //__BITMAP_H_
