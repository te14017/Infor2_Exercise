//
//  ex3_task4.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/3/29.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>

void exchange(int A[], int m, int n) {
    int x = A[m];
    A[m] = A[n];
    A[n] = x;
}

int lomutoPart(int A[], int l, int r, int smallLeft){
    int i = l-1;
    int j=l;
    for(; j<r; j++){
        if(smallLeft == 1){
            if(A[j]<A[r]){
                i++;
                exchange(A, i, j);
            }
        } else if(smallLeft == 0){
            if(A[j]>A[r]){
                i++;
                exchange(A, i, j);
            }
        }
    }
    exchange(A, i+1, r);
    return i+1;
}

void quickSort(int A[], int l, int r, int smallLeft){
    if(l<r){
        int m = lomutoPart(A, l, r, smallLeft);
        quickSort(A, l, m-1, smallLeft);
        quickSort(A, m+1, r, smallLeft);
    }
}

//int main(){
//    int A[] = {4,2,5,3,6,7,8,1,0};
//    int n = sizeof(A)/sizeof(A[0])-1;
//    quickSort(A, 0, n, 1);
//    printf("\nAscending order: ");
//    for(int i=0; i<=n; i++){
//        printf("%d, ", A[i]);
//    }
//    quickSort(A, 0, n, 0);
//    printf("\nDescending order: ");
//    for(int i=0; i<=n; i++){
//        printf("%d, ", A[i]);
//    }
//}