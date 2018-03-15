//
// Created by prog2100 on 15/03/18.
//

#include <iostream>
#include <cstdlib>
#include "Util.h"

void Util::buildArray(int *a, int size)
{
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; ++i)
    {
        a[i] = 1 + rand() % 10;
    }
}

void Util::copyArray(int *a,int *b, int size)
{
    int temp[size];

    for(int i = 0; i < size; i++)
    {
        b[i] = a[i];
    }
}