#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** s(int* a,int len);
void print(int** ans,int len);
int** s(int* a,int len){
    for (int i=0;i<len-1;i++){
        for (int j=0; j<len-1;j++){
            if (a[j]>a[j+1]){
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    int n = sqrt(len);
    int **arr;
    arr = (int**)malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        arr[i] = &a[i*n];
    }
    return arr;
}
void print(int** ans,int len){
    int n = sqrt(len);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    } 
}