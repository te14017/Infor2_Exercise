//
//  ex4_task4.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/4/23.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int arr[16];
    int head;
    int tail;
};

struct queue* init(){
    struct queue* q = malloc(sizeof(struct queue));
    q->head = 0;
    q->tail = 0;
    return q;
}

int isempty(struct queue* q){
    return (q->head == q->tail)? 1:0;
}

void enqueue(struct queue* q, int val){
    q->arr[q->tail] = val;
    q->tail = (q->tail+1)%16;
}

int dequeue(struct queue* q){
    int i = q->head;
    q->head = (q->head+1)%16;
    return q->arr[i];
}

void print(struct queue* q){
    int i = q->head;
    int j = q->tail;
    while(i!=j) {
        printf("%d ", q->arr[i]);
        i = (i+1)%16;
    }
    printf("\n");
}

//int main() {
//    struct queue* q = init();
//    enqueue(q, 4);
//    enqueue(q, 7);
//    enqueue(q, 1);
//    enqueue(q, 2);
//    print(q);
//    dequeue(q);
//    dequeue(q);
//    print(q);
//}