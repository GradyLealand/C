#include <iostream>
#include "Sorter.h"

using namespace std;

Sorter sorter;

int main() {
    int size = 10;
    sorter.setSize(size);

    srand(static_cast<unsigned int>(time(0)));
    int array[size];
    for (int i = 0; i < size; ++i)
    {
        array[i] = 1 + rand() % 10;
    }

    for (int i = 0; i < size; i ++) {
        cout << array[i] << " ";
    }
    cout << endl;

    int quickSize = sizeof(array) / sizeof(array[0]);


    sorter.bubbleSort(array);
    sorter.selectionSort(array);
    sorter.insertionSort(array);
    sorter.shellSort(array);
    sorter.quickSort(array, quickSize);

    return 0;
}