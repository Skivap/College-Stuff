#include <stdio.h>
int main(){
    int x;
    scanf("%d", &x);
    x = x+1;
    for(int i=1;i<x;i++){
        for(int j=0;j<x-1-i;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("%d", j);
        }
        for(int j=i-1;j>0;j--){
        printf("%d", j);
        }
        printf("\n");
    }
}   