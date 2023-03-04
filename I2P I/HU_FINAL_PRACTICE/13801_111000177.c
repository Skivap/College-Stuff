#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, k, temp, mask, solution = 0;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = 0;
        for(int j=0;j<k;j++){
            scanf("%d", &temp);
            arr[i] = arr[i]<<1;
            arr[i] += temp;
        }
    }
    mask = (1<<k) -1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]|arr[j])==mask) solution++;
        }
    }
    printf("%d\n", solution);
}