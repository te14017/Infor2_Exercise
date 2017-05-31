//
//  ex3_task5.c
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

void hoareOddEven(int A[], int l, int r){
    int i=l-1, j=r+1;
    while(1){
        while(A[--j]%2 == 0){
            continue;
        }
        while(A[++i]%2 == 1){
            continue;
        }
        if(i<j){
            exchange(A, i, j);
            continue;
        } else {
            break;
        }
    }
}

int main(){
    int A[] = {4,2,5,3,6,7,8,1,0};
    int n = sizeof(A)/sizeof(A[0])-1;
    hoareOddEven(A, 0, n);
    for(int i=0; i<=n; i++){
        printf("%d, ", A[i]);
    }
}