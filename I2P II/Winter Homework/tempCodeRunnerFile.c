#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int value;
    struct _Node * next;
}Node;
void addNode(Node * temp, int val){
    if(temp->value == -1){
        temp->value = val;
        return;
    }
    if(temp->value < val){
        if(temp->next == NULL){
            temp->next = malloc(sizeof(Node));
            (temp->next)->value = val;
            (temp->next)->next = NULL;
        }
        else addNode(temp->next, val);
    }else{
        Node * temp2 = malloc(sizeof(Node));
        temp2->next = temp->next;
        temp->next = temp2;
        temp2->value = temp->value;
        temp->value = val;
    }
}
int main(){
    int n, input1, input2;
    scanf("%d", &n);
    Node **arr = malloc(n*sizeof(Node*));
    for(int i=0;i<n;i++){
        arr[i] = malloc(sizeof(Node));
        arr[i]->value = -1;
        arr[i]->next = NULL;
    }
    for(int i=0;i<n-1;i++){
        scanf("%d%d", &input1, &input2);
        input1--; input2--;
        addNode(arr[input1], input2); addNode(arr[input2], input1);
    }
    for(int i=0;i<n;i++){
        Node * temp = arr[i];
        while(temp!=NULL){
            printf("%d - ", (temp->value) + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}