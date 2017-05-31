//
//  ex02_Task3.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/3/17.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>

int isReverse(char A[], char B[]) {
    //check if one or two of them are empty
    if(A[0] == '\0' && B[0] == '\0'){
        return 1;
    }
    if(A[0] == '\0' && B[0] != '\0'){
        return 0;
    }
    if(B[0] == '\0' && A[0] != '\0'){
        return 0;
    }
    //now we know both of them are unempty, get the length of them
    int lenA=1, lenB=1;
    for(; A[lenA]!='\0'; lenA++){
    }
    for(; B[lenB]!='\0'; lenB++){
    }
    //A and B should have the same length
    if(lenA != lenB){
        return 0;
    }
    for(int i=0; i<lenA; i++){
        if(A[i] != B[lenA-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char A1[] = "";
    char B1[] = "";
    char A2[] = "";
    char B2[] = "a";
    char A3[] = "abac";
    char B3[] = "cabab";
    char A4[] = "cbbac";
    char B4[] = "cabcc";
    char A5[] = "cacb";
    char B5[] = "bcac";
    printf("Result1: %d\n", isReverse(A1, B1));
    printf("Result2: %d\n", isReverse(A2, B2));
    printf("Result3: %d\n", isReverse(A3, B3));
    printf("Result4: %d\n", isReverse(A4, B4));
    printf("Result5: %d\n", isReverse(A5, B5));
    return 0;
}