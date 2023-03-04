#include <stdio.h>
void binary(unsigned long int x){
    if(x==0) return;
    if(x%2==1){
        binary(x/2);
        printf("1");
    }else{
        binary(x/2);
        printf("0");
    }
}
int main(){
    unsigned long temp;
    scanf("%lu", &temp);
    binary(temp);
    printf("\n");
}