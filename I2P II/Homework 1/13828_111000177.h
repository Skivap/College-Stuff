#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int val;
    struct _node *next;
} node;

node *partition_linked_list(node * L, int pvt){
    node * head1 = malloc(sizeof(node));
    node * temp1 = head1;
    node * head2 = malloc(sizeof(node));
    node * temp2 = head2;
    temp1->next = malloc(sizeof(node));
    temp2->next = malloc(sizeof(node));
    node *temp = L;
    node *del;
    int v;
    while(temp!=NULL){
        v = temp->val;
        if(v < pvt){
            temp1 = temp1->next;
            temp1->val = v;
            temp1->next = malloc(sizeof(node));
        }else{
            temp2 = temp2->next;
            temp2->val = v;
            temp2->next = malloc(sizeof(node));
        }
        del = temp;
        temp = temp->next;
        free(del);
    }
    del = head1;
    head1 = head1->next;
    free(del);
    del = head2;
    head2 = head2->next;
    free(del);
    free(temp1->next);
    free(temp2->next);
    temp1->next = head2;
    temp2->next = NULL;
    return head1;
}