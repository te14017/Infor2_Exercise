//
//  ex6_task2.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/5/18.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#define N 5


void costMatrix(int C[N][N], int M[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i == 0) {M[i][j] = C[i][j];}
            else {M[i][j] = -1;}
        }
    }
    for(int i=1; i<N; i++) {
        for(int j=0; j<N; j++) {
            int minCost = M[i-1][j];
            int leftUpper = -1;
            int rightUpper = -1;
            if(j-1 >= 0) {leftUpper = M[i-1][j-1];}
            if(j+1 <= N-1) {rightUpper = M[i-1][j+1];}
            if(leftUpper != -1 && minCost > leftUpper) {
                minCost = leftUpper;
            }
            if(rightUpper != -1 && minCost > rightUpper) {
                minCost = rightUpper;
            }
            M[i][j] = C[i][j] + minCost;
        }
    }
}

int pathDP(int C[N][N], int row, int col) {
    if(row<0 || row>N-1 || col<0 || col>N-1) {return -1;}
    int M[N][N];
    costMatrix(C, M);
    
    // Warning : this print matrix block will be commented out during time test in Task3 !
    printf("The minimum cost matrix is as follow: \n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf(" %d,", M[i][j]);
        }
        printf("\n");
    }
    return M[row][col];
}

//int main() {
//    int C[N][N] = {{4,1,2,9,7}, {7,9,8,4,0}, {3,6,8,2,4}, {2,7,1,9,5}, {6,8,3,6,1}};
//    printf("\n Test minimum cost for task2: %d\n", pathDP(C, 4, 2));
//    
//}