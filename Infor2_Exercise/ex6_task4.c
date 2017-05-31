//
//  ex6_task4.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/5/19.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#define N 4

#define W 0
#define G 1
#define B 2

int adjMatrix[N][N];
int colorMatrix[N];

// return 1 if there is cycle, 0 otherwise
int DFS_cycle(int A[N][N], int C[N], int row){
    C[row] = G;
    for(int x=0; x<N; x++){
        if(A[row][x] == 1 && (C[x] == G || C[x] == B)){
            return 1;
        }
        if(A[row][x] == 1 && C[x] == W){
            if(DFS_cycle(A, C, x) == 1){
                return 1;
            }
        }
    }
    C[row] = B;
    return 0;
}

int checkForCycles() {
    for(int i=0; i<N; i++){
        // restore every node to White each time
        for(int i=0; i<N; i++){
            colorMatrix[i] = W;
        }
        if(DFS_cycle(adjMatrix, colorMatrix, i) == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            adjMatrix[i][j] = 0;
        }
        colorMatrix[i] = W;
    }
    // test which graph, 0 for the first one, else for the second one
    int test = 0;
    if(test == 0) {
        adjMatrix[1][0] = 1;
        adjMatrix[2][1] = 1;
        adjMatrix[2][3] = 1;
        adjMatrix[3][1] = 1;
        adjMatrix[3][2] = 1;
    } else {
        adjMatrix[1][0] = 1;
        adjMatrix[2][1] = 1;
        adjMatrix[2][0] = 1;
        adjMatrix[3][1] = 1;
    }
//    printf("\n %d \n", DFS_cycle(adjMatrix, colorMatrix, 2));
//    for(int i=0; i<N; i++){
//        printf("%d, ", colorMatrix[i]);
//    }
    if(checkForCycles() == 1) {
        printf("\n The tested graph has cycle inside.\n");
    } else {
        printf("\n The tested graph has no cycle inside.\n");
    }
    
}