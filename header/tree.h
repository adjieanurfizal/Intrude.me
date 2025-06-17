#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LABEL 50

typedef struct TreeNode* Address;

typedef struct TreeNode {
    char label[MAX_LABEL];
    Address firstChild;
    Address nextSibling;
} TreeNode;

Address newNode(const char* label);
void insertChild(Address parent, Address child);
void printTree(Address root, int level);

#endif
