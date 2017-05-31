//
//  ex5_task3.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/5/7.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct tree {
    struct node* root;
};
struct node {
    int val;
    struct node* left;
    struct node* right;
};

struct tree* init(){
    struct tree* t = malloc(sizeof(struct tree));
    t->root = NULL;
    return t;
}

void insert(struct tree* t, int val){
    struct node* n = malloc(sizeof(struct node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    struct node* p = t->root;
    struct node* q = NULL;
    while(p!=NULL){
        q=p;
        if(val<p->val){p = p->left;}
        else {p = p->right;}
    }
    if(q == NULL) {t->root = n;}
    else if(q->val > val) {q->left = n;}
    else {q->right = n;}
}

struct node* search(struct tree* t, int val){
    struct node* p = t->root;
    while(p!=NULL && p->val!=val){
        if(p->val>val){p=p->left;}
        else {p=p->right;}
    }
    return p;
}

void delete(struct tree* t, int val){
    if(search(t, val) == NULL) {
        printf("\nsorry, no such value in the BST.");
        return;
    }
    struct node* p = t->root;
    struct node* n = search(t, val);
    // get parent of deleted node
    if(p->val == n->val){p=NULL;}
    else {
        while(p->left != n && p->right != n){
            if(p->val<n->val){p = p->right;}
            else{p = p->left;}
        }
    }
    // one child case
    if(n->left == NULL){
        if(p==NULL){t->root = n->right;}
        else if(p->left == n){p->left = n->right;}
        else {p->right = n->right;}
    } else if(n->right == NULL){
        if(p==NULL){t->root = n->left;}
        else if(p->left == n){p->left = n->left;}
        else {p->right = n->left;}
    } else { // two child case
        struct node* ps = n;
        struct node* s = n->left;
        while(s->right != NULL) {
            ps = s;
            s = s->right;
        }
        if(p==NULL){t->root = s;}
        else if(p->left == n){p->left = s;}
        else {p->right = s;}
        s->right = n->right;
        if(ps != n){
            ps->right = s->left;
            s->left = n->left;
        }
    }
}

void printNodes(struct node* n) {
    if(n != NULL) {
        printNodes(n->left);
        printf("%d, ", n->val);
        printNodes(n->right);
    }
}

void printTree(struct tree* t){
    struct node* n = t->root;
    printf("\nInorder walk of tree: ");
    printNodes(n);
}

int main(){
    int A[9] = {4, 2, 3, 8, 6, 7, 9, 12, 1};
    struct tree* t = init();
    for(int i=0; i<9; i++){
        insert(t, A[i]);
    }
    printTree(t);
    delete(t, 4);
    delete(t, 7);
    delete(t, 2);
    printTree(t);
}
