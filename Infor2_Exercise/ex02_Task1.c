//
//  ex02_Task1.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/3/17.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>

void swap(int A[], int i, int j) {
    int x = A[i];
    A[i] = A[j];
    A[j] = x;
}

void twoEndSort(int A[], int n) {
    int l=0, r=n;
    while(l < r) {
        int min=l, max=r;
        for(int i=l; i<=r; i++){
            if(A[min] > A[i]) {
                min = i;
            }
            if(A[max] < A[i]){
                max = i;
            }
        }
        swap(A, l, min);
        if (l == max){
            max = min;
        }
        swap(A, r, max);
        l++;
        r--;
    }
}

int main() {
    int A[] = {21,3,51,99,24,63,76,82,40,66};
    int n = sizeof(A)/sizeof(A[0]);
    printf("The original array:\n");
    for(int i=0; i<n; i++) {
        printf("%d, ", A[i]);
    }
    twoEndSort(A, n);
    printf("\nThe sorted array:\n");
    for(int i=0; i<n; i++) {
        printf("%d, ", A[i]);
    }
    return 0;
}
