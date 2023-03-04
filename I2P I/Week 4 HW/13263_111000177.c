#include <stdio.h>
int main(){
    int x;
    scanf("%d", &x);
    if(x%2==0){
        printf("Stop drawing fake diamonds!\n");
    }else{
        for(int i=1;i<=x;i=i+2){
            for(int j=0;j<(x-i)/2;j++){
                printf(" ");
            }
            for(int j=0; j<i;j++){
                printf("*");
            }
            printf("\n");
        }
        for(int i=x-2;i>0;i=i-2){
            for(int j=0;j<(x-i)/2;j++){
                printf(" ");
            }
            for(int j=0; j<i;j++){
                printf("*");
            }
            printf("\n");
        }
    }
}