#include <stdio.h>
int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    int arr[x];
    int domo = 0;
    for(int i=0;i<x;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<=x-y;i++){
        int jumlah = 0;
        for(int j=i+1;j<i+y-1;j++){
            if(arr[j]<=arr[i] || arr[j]<=arr[i+y-1]){
                break;
            }
            jumlah++;
        }
        if(jumlah==y-2){
            domo = 1;
            for(int j=i;j<i+y;j++){
                printf("%d", arr[j]);
                if(j!=i+y-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    if(domo == 0){
        printf("Domo\n");
    }
}