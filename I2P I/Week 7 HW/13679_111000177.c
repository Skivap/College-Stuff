#include <stdio.h>
long int max = 0;
int solution = 0;
int valid(int col, int row, int (*arr)){
    for(int i=0;i<row;i++){
        if(arr[i]==col||arr[i]==col-row+i||arr[i]==col+row-i){
            return 0;
        }
    }
    return 1;
}
void starfruits(int row, int size, int (*arr), int (*points)[size]){
    if(row==size){
        long int sum = 0;
        for(int i=0;i<size;i++){
            sum += points[i][arr[i]];
        }
        if(sum>max||solution == 0){
            max = sum;
        }
        solution++;
        return;
    }
    for(int i=0; i<size; i++){
        if(valid(i,row,arr)){
            arr[row]=i;
            starfruits(row+1,size,arr,points);
        }
    }
    return;
}
int main(){
    int x;
    scanf("%d", &x);
    int points[x][x];
    int position[x];
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            scanf("%d", &points[i][j]);
        }
    }
    starfruits(0, x, position, points);
    if(solution==0){
        printf("no solution\n");
    }else{
        printf("%ld\n", max);
    }
}