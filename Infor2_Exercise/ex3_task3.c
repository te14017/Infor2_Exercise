//
//  ex3_task3.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/3/28.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>

void exchange(int A[], int m, int n) {
    int x = A[m];
    A[m] = A[n];
    A[n] = x;
}

void minHeapify(int A[], int i, int e){
    int m = i;
    int l = 2*(i+1)-1; //left child
    int r = 2*(i+1);  //right child
    if(l<=e && A[l]<A[m]) {
        m=l;
    }
    if(r<=e && A[r]<A[m]) {
        m=r;
    }
    if(i != m) {
        exchange(A, i, m);
        minHeapify(A, m, e);
    }
}

void buildMinHeap(int A[], int n){
    for(int i=(n+1)/2-1; i >= 0; i--){
        minHeapify(A, i, n);
    }
}

void printHeap(int A[], int i, int n){
    //recursively print
    if(i <= (n+1)/2-1){
        int l = 2*(i+1)-1; //left child
        int r = 2*(i+1);  //right child
        printf("%d ----- %d\n", A[i], A[l]);
        printf("%d ----- %d\n", A[i], A[r]);
        printHeap(A, l, n);
        printHeap(A, r, n);
    }
}

void minHeapSort(int A[], int n){
    buildMinHeap(A, n);
    for(int i=n; i>=1; i--){
        exchange(A, 0, i);
        minHeapify(A, 0, i-1);
    }
}

int main(){
    int A[] = {4,2,5,3,6,7,8,1,0};
    int n = sizeof(A)/sizeof(A[0])-1;
    minHeapSort(A, n);
    printHeap(A, 0, n);
}