//
// Created by LYZ on 2021/11/25.
//

#include "DirectInsert.h"

void directInsertSort(int *&arr, int len) {
    int i, j, pivot;
    for (i = 1; i < len; i++) {
        pivot = arr[i];
        for (j = i - 1; j >= 0 and pivot < arr[j]; j--) { // 后移并判断位置
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = pivot;
    }
}