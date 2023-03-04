#include <stdio.h>
int main(){
    int x1, x2, n, temp;
    scanf("%d %d %d", &x1, &x2, &n);
    temp = x1;
    if(n==1){
        temp = x2;
    }
    for(int i=0;i<n-1;i++){
        temp = x1 - x2;
        x1 = x2;
        x2 = temp;
    }
    printf("%d\n", temp);
}