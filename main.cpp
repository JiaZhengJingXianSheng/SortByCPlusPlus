#include <iostream>
#include <cstdlib>
#include "Select.h"
#include "Bubble.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "DirectInsert.h"

using namespace std;

#define MAXSIZE 15

int main() {
    int *arr;
    for (int i = 0; i < MAXSIZE; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

//    selectSort(arr, MAXSIZE);
//    bubbleSort(arr,MAXSIZE);
//    quickSort(arr,0,MAXSIZE-1);
//    heapSort(arr,MAXSIZE);
    directInsertSort(arr, MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
