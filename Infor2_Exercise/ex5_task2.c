//
//  ex5_task1.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/5/6.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct element {
    int val;
    struct element *next;
};

struct element* H[8];

void init(){
    for(int i =0; i<8; i++){
        H[i] = NULL;
    }
}

int h(int val){
    return (8*fmod((val*(sqrt(5)-1)/2),1)/1);
}

void insert(int val) {
    int h_val = h(val);
    struct element* new = malloc(sizeof(struct element));
    new->val = val;
    new->next = NULL;
    if(H[h_val] == NULL) {
        H[h_val] = new;
    } else {
        struct element* p = H[h_val];
        while(p->next != NULL) {p = p->next;}
        p->next = new;
    }
}

struct element* search(int val) {
    int h_val = h(val);
    if(H[h_val] == NULL) {return NULL;}
    else {
        struct element* p = H[h_val];
        while(p != NULL && p->val != val) {
            p = p->next;
        }
        return p;
    }
}

void printHash(){
    for(int i=0; i<8; i++){
        if(H[i]!=NULL){
            printf("\nslot No.%d : ", i);
            struct element* p = H[i];
            while(p!=NULL) {
                printf("%d, ", p->val);
                p = p->next;
            }
        }
    }
}

int main(){
    int A[7] = {111, 10112, 1113, 5568, 63, 1342, 21231};
    int B[5] = {1, 10112, 1113, 5568, 337};
    init();
    for(int i=0; i<7; i++){
        insert(A[i]);
    }
    printHash();
    for(int i=0; i<5; i++){
        struct element* p=search(B[i]);
        if(p==NULL){
            printf("\nnot found: %d", B[i]);
        } else {
            printf("\nfound: %d ", B[i]);
        }
    }
    printf("\n");
}