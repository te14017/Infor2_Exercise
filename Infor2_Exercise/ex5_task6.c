//
//  ex5_task6.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/5/7.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

#define black 0
#define red 1

struct rbNode {
    int key;
    int color;
    struct rbNode* left;
    struct rbNode* right;
    struct rbNode* parent;
};

struct rbTree {
    int bh;
    struct rbNode *root;
    struct rbNode *nil;
};

struct rbTree* rb_initialize() {
    struct rbTree* tree;
    struct rbNode* node;
    
    tree = (struct rbTree*) malloc(sizeof(struct rbTree));
    
    tree->nil = (struct rbNode*) malloc(sizeof(struct rbNode));
    tree->nil->parent = tree->nil;
    tree->nil->left = tree->nil;
    tree->nil->right = tree->nil;
    tree->nil->color = black;
    tree->nil->key = -2;
    
    tree->root = tree->nil;
    tree->bh = 0;
    
    return tree;
}

void rb_leftRotate(struct rbTree* T, struct rbNode* x) {
    // your implementation goes here
    struct rbNode* s = x->right;
    x->right = s->left;
    s->parent = x->parent;
    if(s->left != NULL) {s->left->parent = x;}
    if(x->parent == NULL) {T->root = s;}
    else if(x->parent->left == x) {x->parent->left = s;}
    else {x->parent->right = s;}
    s->left = x;
    x->parent = s;
}

void rb_rightRotate(struct rbTree* T, struct rbNode* y) {
    // your implementation goes here
    struct rbNode* s = y->left;
    y->left = s->right;
    s->parent = y->parent;
    if(s->right != NULL) {s->right->parent = y;}
    if(y->parent == NULL) {T->root = s;}
    else if(y->parent->left == y) {y->parent->left = s;}
    else {y->parent->right = s;}
    s->right = y;
    y->parent = s;
}

void rb_insertFixup(struct rbTree* T, struct rbNode* z) {
    struct rbNode* y;
    while (z->parent->color == red) {
        if (z->parent == z->parent->parent->left) { /* non-mirrored cases */
            y = z->parent->parent->right;
            if (y->color == red) {                    /* case 1 */
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {            /* case 2 */
                    z = z->parent;
                    rb_leftRotate(T, z);
                }
                z->parent->color = black;               /* case 3 */
                z->parent->parent->color = red;
                rb_rightRotate(T, z->parent->parent);
            }
        } else {                                    /* mirrored cases */
            y = z->parent->parent->left;
            if (y->color == red) {                    /* case 1m */
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {             /* case 2m */
                    z = z->parent;
                    rb_rightRotate(T, z);
                }
                z->parent->color = black;               /* case 3m */
                z->parent->parent->color = red;
                rb_leftRotate(T, z->parent->parent);
            }
        }
    }
    if (T->root->color == red) {
        T->bh += 1;
    }
    T->root->color = black;
}

void rb_insert(struct rbTree* tree, int key) {
    struct rbNode *oneDelayed = tree->nil;
    struct rbNode *insertPlace = tree->root;
    struct rbNode *nodeToInsert =
    (struct rbNode*) malloc(sizeof(struct rbNode));
    nodeToInsert->key = key;
    nodeToInsert->color = red;
    
    nodeToInsert->left=tree->nil;
    nodeToInsert->right=tree->nil;
    nodeToInsert->parent=tree->nil;
    while (insertPlace != tree->nil) {
        oneDelayed = insertPlace;
        if (nodeToInsert->key < insertPlace->key) {
            insertPlace = insertPlace->left;
        }
        else {
            insertPlace = insertPlace->right;
        }
    }
    
    if (oneDelayed == tree->nil) {
        tree->root = nodeToInsert;
    }
    else if (oneDelayed->key < nodeToInsert->key) {
        oneDelayed->right = nodeToInsert;
        nodeToInsert->parent = oneDelayed;
    }
    else {
        oneDelayed->left = nodeToInsert;
        nodeToInsert->parent = oneDelayed;
    }
    rb_insertFixup(tree, nodeToInsert);
}

void rb_printRecursive(struct rbNode *root, struct rbTree *tree) {
    if (root == tree->nil) {
        return;
    }
    rb_printRecursive(root->left, tree);
    printf(" %d (%s) -- %d\n", root->key, (root->color==red?"RED":"BLACK"),
           root->left->key);
    rb_printRecursive(root->right, tree);
    printf(" %d (%s) -- %d\n", root->key, (root->color==red?"RED":"BLACK"),
           root->right->key);
}

void rb_print(struct rbTree *tree) {
    printf("graph g {\n");
    rb_printRecursive(tree->root, tree);
    printf("}\n");
}

struct rbNode* rb_search(struct rbTree* T, int q) {
    struct rbNode* x = T->root;
    
    if (x == T->nil) {
        return x;
    }
    while (x->key != q) {
        if (q < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
        if (x == T->nil) {
            return x;
        }
    }
    return x;
}

int main(int argc, char **argv) {
    struct rbTree *t1;
    
    t1 = rb_initialize();
    rb_insert(t1, 10);
    rb_insert(t1, 1);
    rb_insert(t1, 11);
    rb_insert(t1, 9);
    rb_insert(t1, 5);
    rb_insert(t1, 13);
    rb_print(t1);
    return 0;
}

