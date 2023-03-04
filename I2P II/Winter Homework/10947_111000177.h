#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data){
    Node* temp = *nd;
    Node* temp2 = *nd;
    if(*nd==NULL) return;
    if(data==1){
        temp = temp->next;
        free(temp2);
        *nd = temp;
        return;
    }else{
        for(int i=2;i<data;i++){
            if(temp==NULL || temp->next ==NULL) return;
            temp = temp->next;
        }
        if(temp->next==NULL) return;

        temp2 = (temp->next)->next;
        free(temp->next);
        temp->next = temp2;
    }
}
Node* createList(){
    Node* head = NULL;
    Node* temp;
    int num;
    while(1){
        scanf("%d", &num);
        if(num==-1)break;
        else{
            if(head==NULL){
                head = (Node*)malloc(sizeof(Node));
                temp = head;
            }else{
                temp->next = (Node*)malloc(sizeof(Node));
                temp = temp->next;
            }
            temp->data = num;
            temp->next = NULL;
        }
    }
    return head;
}