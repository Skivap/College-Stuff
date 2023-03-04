#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct _Node{
    int number;
    struct _Node* next;
    struct _Node* prev;
}Node;

Node* head;
Node* createList(int n){
    Node ** arr = (Node**)malloc(n*sizeof(Node*));
    for(int i=0; i<n; i++) arr[i] = (Node*)malloc(sizeof(Node));
    for(int i=0; i<n; i++){
        arr[i]->number = i+1;
        arr[i]->next = i==n-1 ? arr[0] : arr[i+1];
        arr[i]->prev = i==0 ? arr[n-1] : arr[i-1];
    }
    Node * tmp = arr[0];
    free(arr);
    return tmp;
}
void solveJosephus(int n, int t){
    Node * cursor = head;
    int step, s = 1;
    Node *b; Node *f;
    while(t--){
        scanf("%d", &step);
        if((step&1) == 0){
            if(s) cursor = cursor->next;
            step = step%n;
            while(step--) cursor = cursor->prev;
            printf("%d\n", cursor->number);
            b = cursor->prev;
            f = cursor->next;
            b->next = f;
            f->prev = b;
            free(cursor);
            cursor = f;
        }else{
            cursor = cursor->prev;
            step = step%n;
            while(step--) cursor = cursor->next;
            printf("%d\n", cursor->number);
            b = cursor->prev;
            f = cursor->next;
            b->next = f;
            f->prev = b;
            free(cursor);
            cursor = f;
        }
        n--;
        s=0;
    }
}

#endif
