//
// Created by LYZ on 2021/11/25.
//

#include "Bubble.h"
void bubbleSort(int* &arr,int len){
    for (int i=0; i<len-1; i++)
    {
        for (int j=0; j<len-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}