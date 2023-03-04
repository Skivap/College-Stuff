#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
} Node;

void Insert(Node** root, int src){
        if(*root==NULL){
            *root=(Node*)malloc(sizeof(Node));
            (*root)->val=src;
            (*root)->left=NULL;
            (*root)->right=NULL;
           // printf("%d",(*root)->val);
        }
       else{
            if(src==(*root)->val)return;
            if(src<(*root)->val){
                Node* ptr=(*root)->left;
                if(ptr==NULL){
                    Node* add=(Node*)malloc(sizeof(Node));
                    add->val=src;
                    add->left=NULL;
                    add->right=NULL;
                    (*root)->left=add;
                }
                else{
                    Insert(&ptr,src);
                }
                
            }
           else if(src>(*root)->val){
                Node* ptr=(*root)->right;
                if(ptr==NULL){
                    Node* add=(Node*)malloc(sizeof(Node));
                    add->val=src;
                    add->left=NULL;
                    add->right=NULL;
                    (*root)->right=add;
                }
                else{
                    Insert(&ptr,src);
                }
                
            }
        }
}
void Print(Node* root){
    int start=0;
    if(start==0){
    if(root==NULL)return;
    Node* print=root;
    printf("%d ",print->val);
    
    if(print->left!=NULL){
        Print((print->left));
    }
    if(print->right!=NULL){
        Print((print->right));
    }
    }
    
}
int main() {
    
    char str[50];
    
    Node* root = NULL;
    
    while (scanf("%s", str) != EOF) {
        if (!strcmp(str, "Insert")) {
            int num;
            scanf("%d", &num);
            
            Insert(&root, num);
        } else if (!strcmp(str, "Print")){
            Print(root);
           // printf("\n");
        }
    }
}