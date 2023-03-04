#include <stdio.h>
unsigned long int solution = 0;
unsigned long int mask = 0;
void compare(unsigned long int a, unsigned long int b, unsigned long int temp){
    printf("%lu %lu %lu\n", a, b,temp);
    if(a==0&&b==0)mask = temp/2 - 1;
    else if(a==0 || b==0){
        mask = 0;
        return;
    }
    else if(a%2 != b%2){
        compare(a/2, b/2, temp*2);
        if(solution == 0) solution = temp-1;
    }
    else compare(a/2, b/2, temp*2);
}
int main(){
    int test;
    unsigned long int a, b;
    scanf("%d", &test);
    while(test--){
        solution = 0;
        mask = 0;
        scanf("%lu %lu", &a, &b);
        compare(a,b, 2);
        //printf("%lu %lu\n", mask, solution);
        if(mask==0){
            printf("0\n");
        }else printf("%lu\n", (mask^solution)&a&b);
    }
}