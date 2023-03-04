//12614 - Game Shopping   
#include <stdio.h>

int main(){
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    int arr[t1];
    int arr2[t2];
    for(int i=0;i<t1;i++)
        scanf("%d", &arr[i]);
    for(int i=0;i<t2;i++)
        scanf("%d", &arr2[i]);
    int x = 0, y = 0, result = 0;
    while(x<t1 && y<t1){
        if(arr[x]<=arr2[y]){
            result++;
            x++;
            y++;
        }else{
            x++;
        }
    }
    printf("%d\n", result);
}