//
// Created by prog2100 on 15/03/18.
//

#include "Sorter.h"
#include <iostream>

using namespace std;

Sorter::Sorter(){}

void Sorter::bubbleSort(int *a) {
    int outer, inner;
    for (outer = testSize - 1; outer > 0; outer--)
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
    printSorted(a);
}

void Sorter::selectionSort(int *a) {
    int outer, inner, min;
    for (outer = 0; outer < testSize - 1; outer++) { // outer counts down
        min = outer;
        for (inner = outer + 1; inner < testSize; inner++) {
            if (a[inner] < a[min]) {
                min = inner;
            }
        }

        // a[min] is least among a[outer]..a[a.length - 1]
        int temp = a[outer];
        a[outer] = a[min];
        a[min] = temp;
    }
    printSorted(a);
}

void Sorter::insertionSort(int *a)
{
    int i, j ,tmp;
    for (i = 1; i < testSize; i++)
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
    printSorted(a);
}

void Sorter::shellSort(int *a)
{
    int i, j, increment;
    for(increment = testSize/2; increment > 0; increment /= 2)
    {
        for(i = increment; i<testSize; i++)
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
    printSorted(a);
}

void Sorter::printSorted(int *a)
{
    for (int i = 0; i < testSize; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int Sorter::partition(int *array, int beg, int end)
//Function to Find Pivot Point
{
    int p = beg, pivot = array[beg], location;

    for (location = beg + 1; location <= end; location++)
    {
        if (pivot>array[location])
        {
            array[p] = array[location];
            array[location] = array[p + 1];
            array[p + 1] = pivot;

            p++;
        }
    }
    return p;
}

void Sorter::quickSort(int *a, int beg, int end, int size)
{
    if (beg<end)
    {
        int pivot = partition(a, beg, end);   //Calling Procedure to Find Pivot
        quickSort(a, beg, pivot - 1, size);         // Subsort left (Recursion)
        quickSort(a, pivot + 1, end, size);	      // Subsort right (Recursion)
    }
    printSorted(a);
}

void Sorter::quickSort(int *a, int size)
{
    quickSort(a, 0, size - 1, size);
}

void Sorter::mergeSort(int *a, int first, int mid, int last, int *temp)
{
    int i = first, j = mid, k;
    for(k = 0; i < mid && j < last; ++k)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i++];
        }
        else
        {
            temp[k] = a[j++];
        }
    }
    for(; i < mid; ++k)
    {
        temp[k] = a[i++];
    }
    for(; j < last; ++k)
    {
        temp[k] = a[j++];
    }
    for(int index = 0; index < last - first; ++index)
    {
        a[first + index] = temp[index];
    }
}


int Sorter::getSize() const {
    return testSize;
}

void Sorter::setSize(int size) {
    Sorter::testSize = size;
}
