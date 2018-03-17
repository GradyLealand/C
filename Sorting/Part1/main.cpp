#include <iostream>
#include "Sorter.h"
#include "Util.h"
#include "RunSort.h"

using namespace std;


int main() {
    RunSort run;
    bool progRun = true;
    int arraySize;

    cout << "What size array would you like to sort? (0 to quit): " ;
    cin >> arraySize;
    cout << endl;

    while(progRun)
    {
        run.sortAll(arraySize);

        cout << endl;
        cout << "What size array would you like to sort? (0 to quit): " ;
        cin >> arraySize;
        cout << endl;

        if(arraySize == 0)
        {
            progRun = false;
        }
    }

    return 0;
}