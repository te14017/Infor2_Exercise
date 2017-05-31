//
//  ex4_task5.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/4/23.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include "ex4_task4.c"

struct stack {
    struct queue* q1;
    struct queue* q2;
};

// initialize stack, q1 as the main value queue
struct stack* initstack(){
    struct stack* s = malloc(sizeof(struct stack));
    s->q1 = init();
    s->q2 = init();
    return s;
}

// all values are enqueued into q1
void push(struct stack* s, int val){
    enqueue(s->q1, val);
}

void swap(struct stack* s){
    struct queue* q = s->q1;
    s->q1 = s->q2;
    s->q2 = q;
}

// dequeue all values of q1 except last one to q2, then make q2 as q1
int pop(struct stack* s){
    while((s->q1->head+1)%16 != s->q1->tail) {
        int v = dequeue(s->q1);
        enqueue(s->q2, v);
    }
    int x = dequeue(s->q1);
    swap(s);
    return x;
}

void printstack(struct stack* s){
    print(s->q1);
}

int main() {
    struct stack* s = initstack();
    int A[] = {8,9,12,3,5};
    int B[] = {11, 4, 21, 6, 2, 5, 13, 14};
    int n1 = sizeof(A)/sizeof(int);
    int n2 = sizeof(B)/sizeof(int);
    for(int i=0; i < n1; i++){
        push(s, A[i]);
    }
    printf("\n after push: ");
    printstack(s);
    printf("%d ",pop(s));
    printf("%d ",pop(s));
    printf("%d ",pop(s));
    printf("\n after pop: ");
    printstack(s);
    for(int i=0; i < n2; i++){
        push(s, B[i]);
    }
    printf("\n after push again: ");
    printstack(s);
}
