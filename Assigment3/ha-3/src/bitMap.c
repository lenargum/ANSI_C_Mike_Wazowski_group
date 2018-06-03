//
// Created by puzankova 02.06.18
//
#include <math.h>
#include "bitMap.h"

int setBitByNumber(int* array, size_t size, int bit, int position)
{

    // array - pointer to the begining of the array
    // position - number of the bit in the 'array'
    // bit - have to be equal to 0 or 1
    //
    // this function changes bit with number 'position' to the 'bit'

    if(array == NULL)
    {
        return 1;
    }

    if(bit != 0 && bit != 1)
    {
        return 2;
    }

    if(position < 1 || position > size)
    {
        return 3;
    }

    *(array + position - 1) = bit;
    return 0;
}

int getBitByNumber(int* array, size_t size, int position)
{
	// this function returns position's bit from the array 

    if(array == NULL)
    {
        return NULL;
    }

    if(position < 1 || position > size)
    {
        return NULL;
    }

    int value = *(array + position - 1);

    if (value != 0 && value != 1)
    {
        return NULL;
    }

    return value;
}

int setBitByAddress(void* position, int bit)
{
	// position - pointer to the bit to change
	// bit - have to be equal to 0 or 1
	//
	// this function changes bit by memory address to 'bit'

    if(position == NULL)
    {
        return 1;
    }

    if(bit != 0 && bit != 1)
    {
        return 2;
    }

    *(int*)position = bit;

    return 0;
}

int getBitByAddress(void* position)
{
	// this function returns first bit by memory address 'position'

    if(position == NULL)
    {
        return NULL;
    }

    int value = *(int*)position;

    if (value != 0 && value != 1)
    {
        return NULL;
    }

    return value;
}