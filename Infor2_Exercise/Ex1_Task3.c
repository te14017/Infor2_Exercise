//
//  Ex1_Task3.c
//  Infor2_Exercise
//
//  Created by 谭特/Te Tan on 17/2/24. Matriculation No.: 16-725-962
//  Copyright © 2017年 谭特/Te Tan. All rights reserved.
//

#include <stdio.h>
#define MAX 256

int main() {
    int A[MAX], B[MAX], result[MAX];
    int num1=0, num2=0, index = 0, sizeA = 0, sizeB = 0;
    //read user input by loop
    printf("Please input values of A seperated by spaces(non number to stop): ");
    while(index < MAX){
        if(!scanf("%d", &num1)) {
            break;
        }
        A[index++] = num1;
        sizeA++;
    }
    fflush(stdin);
    index = 0;
    // ***** read and get rid of the remaining charactor in memory ! *****
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
    printf("Please input values of B seperated by spaces(non number to stop): ");
    while(index < MAX){
        if(!scanf("%d", &num2)) {
            break;
        }
        B[index++] = num2;
        sizeB++;
    }
    // merge A and B into result by comparison
    index = 0;
    int i=0, j=0;
    for(; i<sizeA && j<sizeB;){
        if(A[i] <= B[j]) {
            result[index++] = A[i++];
        } else {
            result[index++] = B[j++];
        }
    }
    if(i < sizeA) {
        for(int m=i; m < sizeA; m++,index++){
            result[index] = A[m];
        }
    }
    if(j < sizeB) {
        for(int m=j; m < sizeB; m++,index++) {
            result[index] = B[m];
        }
    }
    for(int m=0;m < index; m++){
        printf("%d ", result[m]);
    }
    printf("\n");
    return 0;
}
