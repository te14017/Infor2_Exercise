//
//  Ex1_Task6.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/2/25.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

double average(double A[], int n){
    if(n == 1) {
        return A[n-1];
    } else {
        return (average(A, n-1)*(n-1)+A[n-1])/n;
    }
}

int main() {
    double A[] = {2.1, 4.1, 4.8, 8.3, 9.5, 1.4};
    int len;
    GET_ARRAY_LEN(A, len);
    double avr = average(A, len);
    printf("The average of array is: %f\n", avr);
}