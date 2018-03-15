#include <iostream>
#include "Sorter.h"
#include "Util.h"
#include "RunSort.h"

using namespace std;


int main() {
    RunSort run;

    run.sortAll(1000);
    run.sortAll(25000);
    run.sortAll(50000);
    run.sortAll(75000);
    run.sortAll(100000);

    return 0;
}