#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int value;
    int visited;
    struct tree * d1;
    struct tree * d2;
    struct tree * d3;
}tree;

void assign(tree *node1, tree *node2){
    if(node1->d1==NULL)
        node1->d1 = node2;
    else if(node1->d2==NULL)
        node1->d2 = node2;
    else{
        if(node1->d3==NULL){
            tree* temp = malloc(sizeof(tree));
            temp->value = 0;
            temp->visited = 0;
            temp->d1 = NULL;
            temp->d2 = NULL;
            temp->d3 = NULL;
            node1->d3 = temp;
        }
        assign(node1->d3, node2);
    }
}
int check(tree *node){
    if(node->visited) return 0;
    node->visited = 1;
    int sum = node->value;
    if(node->d1!=NULL) sum += check(node->d1);
    if(node->d2!=NULL) sum += check(node->d2);
    if(node->d3!=NULL) sum += check(node->d3);
    node->value = sum;
    return sum;
}

int main(){
    int n, x, d, temp1, temp2;
    int first = 1;
    scanf("%d %d %d", &n, &x, &d);
    tree** arr = malloc(n*sizeof(tree*));
    for(int i=0;i<n;i++){
        scanf("%d\n", &temp1);
        arr[i] = malloc(sizeof(tree));
        arr[i]->value = temp1;
        arr[i]->visited = 0;
        arr[i]->d1 = NULL;
        arr[i]->d2 = NULL;
        arr[i]->d3 = NULL;
    }
    for(int i=0;i<n-1;i++){
        scanf("%d %d", &temp1, &temp2);
        temp1--; temp2--;
        assign(arr[temp1], arr[temp2]);
        assign(arr[temp2], arr[temp1]);
    }
    check(arr[0]);
    for(int i=0;i<n;i++){
        if(abs(arr[i]->value-x)<d){
            if(first){
                printf("%d", i+1);
                first = 0;
            }else{
                printf(" %d", i+1);
            }
        }
    }
    printf("\n");
}