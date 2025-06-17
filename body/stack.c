#include "../header/stack.h"

Stack stackVoting = NULL;
Stack stackReClue = NULL;

void SetTop(Stack *S, Stack NewTop) {
    if (NewTop != NULL) {
        *S = NewTop;
    }
}

void CreateStack(Stack *S) {
    *S = NULL;
}

bool IsStackEmpty(Stack S) {
    return (S == NULL);
}

void Push(Stack *S, infotype X) {
    InsVFirst((List*)S, X);
}

void Pop(Stack *S, infotype *X) {
    DelVFirst((List*)S, X);
}

void PrintStack(Stack S, void (*printFunc)(infotype)) {
    address P = S;
    while (P != NULL) {
        printFunc(Info(P));
        P = Next(P);
    }
}
