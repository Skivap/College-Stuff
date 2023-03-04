#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
    int val;
    struct _node *next;
} node;

bool is_palindrome(node *head){
    node ** arr = (node**)malloc(100000*sizeof(node*));
    int i = 0;
    node* tmp = head;
    while(tmp != NULL){
        arr[i] = tmp;
        i++;
        tmp = tmp->next;
    }
    for(int j = 0; j < i/2; j++){
        if(arr[j]->val != arr[i - 1 - j]->val){
            free(arr);
            return false;
        }
    }
    free(arr);
    return true;
} // return true value if the linked list is a palindrome, otherwise false
