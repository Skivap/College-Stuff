#include <stdio.h>
int main(){
    int x;
    scanf("%d", &x);
    int array[32];
    int digit = 0;
    if(x == 0){
        printf("0");
    }
    else{
        while(x > 0){
        array[digit] = x%2;
        x = x/2;
        digit +=1;
        }
    }

    for(int i=digit;i>0;i--){
        printf("%d", array[i-1]);
    }
    printf("\n");
}