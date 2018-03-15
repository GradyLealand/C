//
// Created by prog2100 on 15/03/18.
//

#ifndef PART1_BUBBLESORT_H
#define PART1_BUBBLESORT_H


class Sorter {
private:
    int testSize;

public:
    Sorter();
    void bubbleSort(int a[]);
    void selectionSort(int *a);
    void insertionSort(int *a);
    void shellSort(int *a);
    void mergeSort(int *a, int first, int last, int *temp);
    void merge(int *a, int first, int mid, int last, int *temp);
    void quickSort(int a[], int beg, int end, int size);
    void quickSort(int a[], int size);
    int partition(int a[], int beg, int end);
    void printSorted(int a[]);
    int getSize() const;
    void setSize(int size);
};


#endif //PART1_BUBBLESORT_H
