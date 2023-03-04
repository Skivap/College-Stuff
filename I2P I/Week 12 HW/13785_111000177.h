#include <stdlib.h>
#include <stdio.h>
int i = 1;
typedef struct node {
    int val;
    struct node *left, *right;
} Node;

void Insert(Node** root, int src){
    if(*root==NULL){
        *root = (Node*)malloc(sizeof(Node));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->val = src;
    }else{
        if(src==(*root)->val) return;
        if(src<(*root)->val)
            Insert(&((*root)->left), src);
        else
            Insert(&((*root)->right), src);
    }
    return;
}
void Print(Node* root){
    if(i){
        i = 0;
        printf("%d", root->val);
        if(root->left!=NULL)Print(root->left);
        if(root->right!=NULL)Print(root->right);
        printf("\n");
        i = 1;
    }else{
        printf(" %d", root->val);
        if(root->left!=NULL)Print(root->left);
        if(root->right!=NULL)Print(root->right);
    }
    return;
}