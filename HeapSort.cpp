//
// Created by LYZ on 2021/11/25.
//

#include "HeapSort.h"
// 生成大根堆
void adjust(int* &arr, int len, int index)
{
    int left = 2*index + 1; // 左孩子
    int right = 2*index + 2;// 右孩子

    int midIndex = index;
    if(left<len && arr[left] > arr[midIndex])
        midIndex = left;
    if(right<len && arr[right] > arr[midIndex])
        midIndex = right;

    if(midIndex != index)
    {
        int temp;
        temp = arr[midIndex];
        arr[midIndex] = arr[index];
        arr[index] = temp;
        adjust(arr, len, midIndex);
    }
}
void heapSort(int* &arr, int len ){
    // 从最后一个无序节点双亲开始
    for(int i=len/2 - 1; i >= 0; i--)
    {
        adjust(arr, len, i);
    }
    for(int i = len - 1; i >= 1; i--)
    {
        // 根节点和最后一个无序节点交换
        int temp;
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        adjust(arr, i, 0);    // 对无序节点继续生成大根堆
    }
}