//
// Created by prog2100 on 15/03/18.
//

#include <iostream>
#include "RunSort.h"

using namespace std;

void RunSort::sortAll(int size)
{
    Sorter sorter;
    Util util;

    //clock variables
    clock_t start;
    double duration;

    sorter.setSize(size);

    int array[size];
    int sortMe[size];

    util.buildArray(array, size);
    util.copyArray(array, sortMe, size);

    if(size == 1000)
    {
        cout << "---------------------initial array---------------------" << endl;
        //print unsorted array
        for (int i = 0; i < size; i ++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }



    cout << "---------------------Array size " << size << "---------------------" << endl;
    /*
     * run each sort on the sortMe array
     * reset SortMe after each sort
     */
    cout << "bubble: ";
    start = clock();
    sorter.bubbleSort(sortMe);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "time: " << duration << endl;
    if(size == 1000)
    {
        sorter.printSorted(sortMe);
    }
    if(size == 1000)
    {

    }
    util.copyArray(array, sortMe, size);

    cout << "Selection: ";
    start = clock();
    sorter.selectionSort(sortMe);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "time: " << duration << endl;
    if(size == 1000)
    {
        sorter.printSorted(sortMe);
    }
    util.copyArray(array, sortMe, size);

    cout << "Insertion: ";
    start = clock();
    sorter.insertionSort(sortMe);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "time: " << duration << endl;
    if(size == 1000)
    {
        sorter.printSorted(sortMe);
    }
    util.copyArray(array, sortMe, size);

    cout << "Shell: ";
    start = clock();
    sorter.shellSort(sortMe);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "time: " << duration << endl;
    if(size == 1000)
    {
        sorter.printSorted(sortMe);
    }
    util.copyArray(array, sortMe, size);

    //int for quick sort
    int quickSize = sizeof(array) / sizeof(array[0]);

    cout << "Quick: ";
    start = clock();
    sorter.quickSort(sortMe, quickSize);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "time: " << duration << endl;
    if(size == 1000)
    {
        sorter.printSorted(sortMe);
    }
    util.copyArray(array, sortMe, size);

    cout << "Merge: ";
    start = clock();
    sorter.mergeSort(sortMe, 0, size, sortMe);
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "time: " << duration << endl;
    if(size == 1000)
    {
        sorter.printSorted(sortMe);
    }

}