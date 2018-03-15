//
// Created by prog2100 on 15/03/18.
//

#ifndef PART1_BUBBLESORT_H
#define PART1_BUBBLESORT_H


class Sorter {
private:
    int size;

public:
    void Sorter(int size);
    void bubbleSort(int a[]);
    void selection(int a[]);
    void insertion(int a[]);
    void Shell(int a[]);
    void Merger(int a[]);
    void QuickSort(int a[]);

    int getSize() const;
    void setSize(int size);
};


#endif //PART1_BUBBLESORT_H
