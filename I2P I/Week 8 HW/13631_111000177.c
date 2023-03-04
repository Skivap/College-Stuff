#include <stdio.h>
#include <stdlib.h>
int nugget(int *arr, int k, int temp, int n, int start){
    if(temp==n)return 1;
    if(temp>n)return 0;
    int result = 0;
    for(int i=start;i<k;i++){
        result += nugget(arr, k, temp+arr[i], n, i);
    }
    return result;

}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr;
    arr = malloc(k * sizeof(int));
    for(int i=0;i<k;i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", nugget(arr,k ,0 , n, 0));
    free(arr);
    return 0;
}