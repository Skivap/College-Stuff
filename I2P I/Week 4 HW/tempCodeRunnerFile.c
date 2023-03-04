#include <stdio.h>

int main(){
    int x, rotate, temp;
    scanf("%d", &x);
    int arr[x][x];
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    scanf("%d", &rotate);
    if(rotate==0){
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                printf("%d",arr[i][j]);
                if(j!=x-1){
                    printf(" ");
                }
            }   
            printf("\n");
        }
    }
    if(rotate==180){
        for(int i=x-1;i>=0;i--){
            for(int j=x-1;j>=0;j--){
                printf("%d",arr[i][j]);
                if(j!=x-1){
                    printf(" ");
                }
            }   
            printf("\n");
        }
    }
    if(rotate==90){
        for(int j=x-1;j>=0;j--){
            for(int i=0; i<x;i++){
                printf("%d",arr[i][j]);
                if(i!=x-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    if(rotate==270){
        for(int j=0;j<x;j++){
            for(int i=x-1; i>=0;i--){
                printf("%d",arr[i][j]);
                if(i!=x-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}