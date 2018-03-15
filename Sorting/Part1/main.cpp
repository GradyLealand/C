#include <iostream>
#include "Sorter.h"

using namespace std;
int main() {
    Sorter sorter = new Sorter(10);
    srand(static_cast<unsigned int>(time(0)));
    int array[10];
    for (int i = 0; i < 10; ++i)
    {
        array[i] = 1 + rand() % 10;
    }

    for (int &i : array) {
        cout << array[i] << " ";
    }
    cout << endl;

    sorter.bubbleSort(array);

    return 0;
}