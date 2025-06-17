// tree.h
#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LABEL 50

typedef struct TreeNode* Address;

typedef struct TreeNode {
    char label[MAX_LABEL];        // Nama kategori atau kata
    Address firstChild;           // Anak pertama
    Address nextSibling;          // Saudara berikutnya
} TreeNode;

// Konstruktor
Address newNode(char* label);

// Operasi tree
void insertChild(Address parent, Address child);
void printTree(Address root, int level);

#endif
