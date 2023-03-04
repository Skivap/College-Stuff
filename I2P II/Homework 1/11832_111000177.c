#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int value;
    struct _Node * next;
}Node;

void addNode(Node ** head, int v1, int v2){
    Node * temp = (Node*)malloc(sizeof(Node));
    temp->value = v2;
    Node * tmp1 = *head;
    if(v1==0){
        temp->next = *head;
        *head = temp;
    }else{
        v1 -= 1;
        while(v1--){
            if (tmp1->next != NULL)
                tmp1 = tmp1->next;
        }
        temp->next = tmp1->next;
        tmp1->next = temp;
    }
}

void cutNode(Node ** head, int v1, int v2){
    if(v1==0) return;
    Node * hd1;
    Node * tmp1 = *head;
    Node * tmp2;
    Node * hd2;
    v1 -= 1;
    while(v1--){
        tmp1 = tmp1->next;
    }
    hd1 = tmp1->next;
    tmp2 = tmp1;
    while(v2--){
        tmp2 = tmp2->next;
    }
    hd2 = tmp2->next;
    tmp1->next = hd2;
    tmp2->next = *head;
    *head = hd1;
}

int main(){
    int t1, t2, v, temp1, temp2;
    char con[5];
    scanf("%d %d", &t1, &t2);
    Node * head = (Node*)malloc(sizeof(Node));
    Node * temp = head;
    while(t1--){
        scanf("%d", &v);
        temp->next = (Node*)malloc(sizeof(Node));
        temp = temp->next;
        temp->value = v;
    }
    temp->next = NULL;
    temp = head;
    head = head->next;
    free(temp);

    while(t2--){
        scanf("%s %d %d", con, &temp1, &temp2);
        if(con[0]=='A'){
            addNode(&head, temp1, temp2);
        }else if (con[0]=='C'){
            cutNode(&head, temp1, temp2);
        }
    }
    temp = head;
    while(head!=NULL){
        printf("%d\n", head->value);
        head = head->next;
        free(temp);
        temp = head;
    }
}