//
//  ex6_task1.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/5/18.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#define N 5

int pathRecursive(int C[N][N], int row, int col) {
    if(row == 0) {return C[row][col];}
    int upper = pathRecursive(C, row-1, col);
    int minCost = upper;
    int flag = 0;
    int leftUpper = -1;
    int rightUpper = -1;
    if(col-1 >= 0) {
        leftUpper = pathRecursive(C, row-1, col-1);
    }
    if(col+1 <= N-1) {
        rightUpper = pathRecursive(C, row-1, col+1);
    }
    // chose the minimum upper cost
    if(leftUpper != -1 && minCost > leftUpper) {
        minCost = leftUpper;
        flag = 1;
    }
    if(rightUpper != -1 && minCost > rightUpper) {
        minCost = rightUpper;
        flag = 2;
    }
    // print the chosen cell
//    if(1){
//        if(flag == 0) {printf("\n [%d, %d] ", row-1, col);}
//        else if(flag == 1) {printf("\n [%d, %d] ", row-1, col-1);}
//        else {printf("\n [%d, %d] ", row-1, col+1);}
//    }
    return C[row][col]+minCost;
}

//int main() {
//    int C[N][N] = {{4,1,2,9,7}, {7,9,8,4,0}, {3,6,8,2,4}, {2,7,1,9,5}, {6,8,3,6,1}};
//    printf("\n Test minimum cost for task1: %d\n", pathRecursive(C, 4, 2));
//}