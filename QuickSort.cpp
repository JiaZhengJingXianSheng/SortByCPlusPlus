//
// Created by LYZ on 2021/11/25.
//

#include "QuickSort.h"
void quickSort(int* &arr,int left, int right){
    if (left< right)
    {
        int i = left, j = right, pivot = arr[left];
        while (i < j)
        {
            while(i < j && arr[j]>= pivot) // 从右向左找第一个小于基准的值
                j--;
            if(i < j) //防止越过自己本身
                arr[i++] = arr[j];
            while(i < j && arr[i]< pivot) // 从左向右找第一个大于等于基准的值
                i++;
            if(i < j) //防止越过自己本身
                arr[j--] = arr[i];
        }
        arr[i] = pivot;
        quickSort(arr, left, i - 1); //左边递归
        quickSort(arr, i + 1, right); //右边递归
    }
}