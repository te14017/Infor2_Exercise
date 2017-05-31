//
//  ex4_task2.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/4/23.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include "ex4_task1.c"
#include <stdbool.h>

struct list* addTwoList(struct list* l1, struct list* l2) {
    struct node* p = l1->head;
    struct node* q = l2->head;
    struct list* l = init();
    //boolean to judge if it is first node
    bool isHead = 1;
    // carry to calculate addition
    int carry = 0;
    // mark the tail of the new established list
    struct node* tail = NULL;
    // continue until the end of every list and no carry
    while(p!=NULL || q!=NULL || carry!=0){
        struct node* n = malloc(sizeof(struct node));
        int x;
        if(p==NULL && q==NULL){
            x = carry;
        } else if(p==NULL){
            x = q->val + carry;
        } else if (q==NULL){
            x = p->val + carry;
        } else{
            x= p->val + q->val + carry;
        }
        carry = x/10;
        n->val = x%10;
        if(!isHead){
            tail->next = n;
        }
        tail = n;
        // update the head of list if its first node
        if(isHead){
            l->head = n;
            isHead = false;
        }
        p = p->next;
        q = q->next;
    }
    return l;
}

int main(){
    struct list* l1 = init();
    struct list* l2 = init();
    int A[] = {9, 4, 5, 3, 1, 2, 0};
    int B[] = {9, 4, 5, 3, 1, 2, 0};
    int n1 = sizeof(A)/sizeof(int);
    int n2 = sizeof(B)/sizeof(int);
    for(int i=0; i < n1; i++){
        append(l1, A[i]);
    }
    for(int i=0; i < n2; i++){
        append(l2, B[i]);
    }
    struct list* l = addTwoList(l1, l2);
    print(l);
}
