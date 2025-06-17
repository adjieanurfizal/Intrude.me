#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "linkedlist.h"

// Stack adalah alias dari address (top of stack)
typedef address Stack;

extern Stack stackVoting;
extern Stack stackReClue;

void SetTop(Stack *S, Stack NewTop);
void CreateStack(Stack *S);
bool IsStackEmpty(Stack S);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X);
void PrintStack(Stack S, void (*printFunc)(infotype));

#endif
