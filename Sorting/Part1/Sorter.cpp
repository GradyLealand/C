//
// Created by prog2100 on 15/03/18.
//

#include "Sorter.h"
#include <iostream>

using namespace std;

Sorter::Sorter(int size)
{
    this->size = size;
}

void Sorter::bubbleSort(int *a) {
    int outer, inner;
    for (outer = size - 1; outer > 0; outer--)
    {  // counting down
        for (inner = 0; inner < outer; inner++)
        {
            // bubbling up
            if (a[inner] > a[inner + 1])
            {
                // if out of order...swap
                int temp = a[inner];
                a[inner] = a[inner + 1];
                a[inner + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Sorter::selection(int *a) {
    int outer, inner, min;
    for (outer = 0; outer < size - 1; outer++) { // outer counts down
        min = outer;
        for (inner = outer + 1; inner < size; inner++) {
            if (a[inner] < a[min]) {
                min = inner;
            }
        }

        // a[min] is least among a[outer]..a[a.length - 1]
        int temp = a[outer];
        a[outer] = a[min];
        a[min] = temp;

    }
}
void Sorter::insertion(int *a)
{
    int i, j ,tmp;

    for (i = 1; i < size; i++)

    {

        j = i;

        while (j > 0 && a[j - 1] > a[j])

        {

            tmp = a[j];

            a[j] = a[j - 1];

            a[j - 1] = tmp;

            j--;

        } //end of while loop

    } //end of for loop
}

void Sorter::Shell(int *a)
{
    int i, j, increment;
    for(increment = size/2; increment > 0; increment /= 2)
    {
        for(i = increment; i<size; i++)
        {
            int temp = a[i];
            for(j = i; j >= increment; j-=increment)
            {
                if(temp < a[j-increment])
                {
                    a[j] = a[j-increment];
                }
                else
                {
                    break;
                }
            }
            a[j] = temp;
        }
    }
}


int Sorter::getSize() const {
    return size;
}

void Sorter::setSize(int size) {
    Sorter::size = size;
}
