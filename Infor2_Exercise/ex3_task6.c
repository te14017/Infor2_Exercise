//
//  ex3_task6.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/3/29.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include "ex3_task4.c"
#include <time.h>
#define ROW 3
#define COL 4

void readFile(char filename[], int output[]){
    FILE *f;
    int i=0;
    f=fopen(filename, "r");
    while(fscanf(f, "%d", &output[i]) == 1){
        i++;
    }
    fclose(f);
}

void printResult(float A[ROW][COL]){
    printf("       Ordered    random    inverse    equal\n");
    printf("120000   %.3f   %.3f   %.3f   %.3f \n", A[0][0], A[0][1], A[0][2], A[0][3]);
    printf("240000   %.3f   %.3f   %.3f   %.3f \n", A[1][0], A[1][1], A[1][2], A[1][3]);
    printf("480000   %.3f   %.3f   %.3f   %.3f \n", A[2][0], A[2][1], A[2][2], A[2][3]);
}

float executeTime(void f(int [], int, int, int), void read(char [], int []), int l, int r, int sL, char filename[], int out[]){
    read(filename, out);
    clock_t start=clock();
    f(out, l, r, sL);
    clock_t end=clock();
    float t = (float)(end-start);
    return t;
}

int main(){
    float A[ROW][COL];
    int output[500000];
    A[0][0]=executeTime(quickSort, readFile, 0, 120000-1, 1, "ordered_asc_120000.txt", output);
    A[1][0]=executeTime(quickSort, readFile, 0, 240000-1, 1, "ordered_asc_240000.txt", output);
    A[2][0]=executeTime(quickSort, readFile, 0, 480000-1, 1, "ordered_asc_480000.txt", output);
    A[0][1]=executeTime(quickSort, readFile, 0, 120000-1, 1, "random_120000.txt", output);
    A[1][1]=executeTime(quickSort, readFile, 0, 240000-1, 1, "random_240000.txt", output);
    A[2][1]=executeTime(quickSort, readFile, 0, 480000-1, 1, "random_480000.txt", output);
    A[0][2]=executeTime(quickSort, readFile, 0, 120000-1, 1, "ordered_desc_120000.txt", output);
    A[1][2]=executeTime(quickSort, readFile, 0, 240000-1, 1, "ordered_desc_240000.txt", output);
    A[2][2]=executeTime(quickSort, readFile, 0, 480000-1, 1, "ordered_desc_480000.txt", output);
    A[0][3]=executeTime(quickSort, readFile, 0, 120000-1, 1, "equal_120000.txt", output);
    A[1][3]=executeTime(quickSort, readFile, 0, 240000-1, 1, "equal_240000.txt", output);
    A[2][3]=executeTime(quickSort, readFile, 0, 480000-1, 1, "equal_480000.txt", output);
    printResult(A);
}

