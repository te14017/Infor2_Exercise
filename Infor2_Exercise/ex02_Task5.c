//
//  ex02_Task5.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/3/17.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>

int tenarySearch(int A[], int l, int r, int k){
    if(l == r){
        return (A[l]==k)?l:-1;
    }
    int mid = (r-l+1)/3;
    int left = tenarySearch(A, l, l+mid-1, k);
    int midd = tenarySearch(A, l+mid, l+2*mid-1, k);
    int right = tenarySearch(A, l+2*mid, r, k);
    if(left != -1){
        return left;
    } else if(midd != -1){
        return midd;
    } else if(right != -1){
        return right;
    } else {
        return -1;
    }
}

int main(){
    int A[] = {14, 21, 83, 79, 11, 33, 68, 42, 57};
    printf("been found? : %d\n", tenarySearch(A, 0, 8, 11));
    printf("been found? : %d\n", tenarySearch(A, 0, 8, 77));
    return 0;
}