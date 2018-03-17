//
// Created by prog2100 on 15/03/18.
//

#include <iostream>
#include <fstream>
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
        writeFile("/home/prog2100/CLionProjects/GitHub/Sorting/Part1/test.txt", "un-sorted", array, size);
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
        writeFile("/home/prog2100/CLionProjects/GitHub/Sorting/Part1/test.txt", "Bubble", sortMe, size);
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
        writeFile("/home/prog2100/CLionProjects/GitHub/Sorting/Part1/test.txt", "Selection", sortMe, size);
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
        writeFile("/home/prog2100/CLionProjects/GitHub/Sorting/Part1/test.txt", "Insertion", sortMe, size);
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
        writeFile("/home/prog2100/CLionProjects/GitHub/Sorting/Part1/test.txt", "Shell", sortMe, size);
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
        writeFile("/home/prog2100/CLionProjects/GitHub/Sorting/Part1/test.txt", "Quick", sortMe, size);
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
        writeFile("/home/prog2100/CLionProjects/GitHub/Sorting/Part1/test.txt", "Merge", sortMe, size);
    }

}

void RunSort::writeFile(string writeFile, string type, int *a, int size)
{
    ofstream fileOut;

    //to append to a file - use ios::app
    try
    {
        fileOut.open(writeFile,ios::app);
        fileOut.exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
    }
    catch(const ofstream::failure& e)
    {
        cout << "Error opening write file";
    }
    catch(std::exception const& e)
    {
        cout << "There was an error: " << e.what() << endl;
    }


    if (fileOut.is_open())//or if(myFileOut.fail)
    {
        fileOut << type << ": ";

        for (int i = 0; i < size; i ++) {
            fileOut << a[i] << " ";
        }
        fileOut << endl;
    }
    else if(fileOut.fail())
    {
        cout << "Output file failed to open" << endl;
        cin.ignore();
    }

    try{
        fileOut.close();
    }
    catch(exception& e)
    {
        cout << "error while closing write file";
    }
}