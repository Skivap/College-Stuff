#include <stdio.h>

int main(void){
    int x;
    scanf("%d", &x);
    printf("%d%d%d%d\n", x/8, (x%8)/4, (x%4)/2, (x%2)/1);
    return 0;
}