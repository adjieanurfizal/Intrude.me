#include "../header/tree.h"

Address newNode(char* label) {
    Address p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL) {
        strncpy(p->label, label, MAX_LABEL);
        p->firstChild = NULL;
        p->nextSibling = NULL;
    }
    return p;
}

void insertChild(Address parent, Address child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        Address temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void printTree(Address root, int level) {
    if (root == NULL) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("- %s\n", root->label);
    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}
