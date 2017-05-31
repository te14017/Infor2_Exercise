//
//  Ex1_Task2.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/2/24.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAX 256

int main() {
    int A[MAX];
    int num=0, index = 0, size =0;
    int sum = 0;
    double average;
    //read user input by loop
    printf("Please input values of A seperated by spaces(non number to stop): ");
    while(index < MAX){
        if(!scanf("%d", &num)) {
            break;
        }
        A[index] = num;
        size++;
        sum += A[index++];
    }
    //calculate average and closest value
    average = sum / size;
    int close_value = A[0];
    for(int i = 1; i < size; i++) {
        if(fabs(A[i]-average) < fabs(close_value-average)){
            close_value = A[i];
        }
    }
    printf("Average: %f\nClosest Element: %d\n", average, close_value);
    return 0;
}