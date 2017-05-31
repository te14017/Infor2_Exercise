//
//  ex4_task1.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/4/23.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct list{
    struct node* head;
};

struct list* init() {
    struct node* head = NULL;
    struct list* l = malloc(sizeof(struct list));
    l->head = head;
    return l;
}

void append(struct list* l, int val) {
    struct node* n = malloc(sizeof(struct node));
    n->val = val;
    n->next = NULL;
    struct node* p = l->head;
    if(p == NULL) {
        l->head = n;
        return;
    }
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = n;
    return;
}

void print(struct list* l) {
    printf("[ ");
    struct node* p = l->head;
    while(p!=NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("]\n");
}

void delete(struct list* l, int i){
    struct node* p = l->head;
    if(i == 0){
        l->head = p->next;
        //free(p);
        return;
    }
    for(int c=0; c<i-1; c++){
        p = p->next;
    }
    if(p->next->next != NULL) {
        p->next = p->next->next;
    } else {
        p->next = NULL;
    }
    free(p->next);
}

//int main(){
//    struct list* l = init();
//    int A[] = {9, 4, 5, 3, 1, 2, 0};
//    int n = sizeof(A)/sizeof(int);
//    for(int i=0; i < n; i++){
//        append(l, A[i]);
//    }
//    print(l);
//    delete(l, 6);
//    delete(l, 3);
//    delete(l, 0);
//    print(l);
//}