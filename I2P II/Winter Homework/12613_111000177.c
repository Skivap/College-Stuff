//12613 - Yet Another Meme Problem   
#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    unsigned long long int a, b, mult, val;
    while(t--){
        scanf("%llu %llu", &a, &b);
        mult = 9;
        val = 0;
        while(mult<=b){
            mult = mult*10 + 9;
            val++;
        }
        printf("%llu\n", a*val);
    }
}