//
//  ex5_task4.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/5/7.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include "ex5_task3.c"

struct node* minimum(struct node* n){
    if(n==NULL){return NULL;}
    struct node* m = n;
    if(m->left != NULL) {
        m = m->left;
    }
    return m;
}

struct node* successor(struct tree* t, struct node* n){
    if(n->right!=NULL) {return minimum(n->right);}
    struct node* p = t->root;
    struct node* q = NULL;
    while(p != n) {
        if(p->val>n->val) {
            q = p;
            p = p->left;
        } else {p = p->right;}
    }
    return q;
}

struct node* ith_smallest(struct tree* t, int i){
    if(i == 1) {
        return minimum(t->root);
    }
    struct node* n = ith_smallest(t, i-1);
    return successor(t, n);
}

