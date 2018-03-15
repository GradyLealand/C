#include <iostream>
#include "Sorter.h"
#include "Util.h"

using namespace std;


int main() {
    Sorter sorter;
    Util util;

    int size = 10;
    sorter.setSize(size);

    int array[size];
    int sortMe[size];

    util.buildArray(array, size);
    util.copyArray(array, sortMe, size);

    //print unsorted array
    for (int i = 0; i < size; i ++) {
        cout << array[i] << " ";
    }
    cout << endl;



    /*
     * run each sort on the sortMe array
     * reset SortMe after each sort
     */
    sorter.bubbleSort(sortMe);
    util.copyArray(array, sortMe, size);

    sorter.selectionSort(sortMe);
    util.copyArray(array, sortMe, size);

    sorter.insertionSort(sortMe);
    util.copyArray(array, sortMe, size);

    sorter.shellSort(sortMe);
    util.copyArray(array, sortMe, size);

    //int for quick sort
    int quickSize = sizeof(array) / sizeof(array[0]);

    sorter.quickSort(sortMe, quickSize);
    util.copyArray(array, sortMe, size);

    sorter.mergeSort(sortMe, 0, size, sortMe);

    return 0;
}