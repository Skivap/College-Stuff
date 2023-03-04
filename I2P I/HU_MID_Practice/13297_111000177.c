#include <stdio.h>
int main(){
    int x,y;
    scanf("%d %d", &x, &y);
    int matrix_1[x][y];
    int matrix_2[y][x];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf("%d", &matrix_1[i][j]);
        }
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            scanf("%d", &matrix_2[i][j]);
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            int temp = 0;
            for(int k=0;k<y;k++){
                temp += matrix_1[j][k]*matrix_2[k][i];
            }
            printf("%d", temp);
            if(j!=x-1){
                printf(" ");
            }

        }
        printf("\n");
    }
}