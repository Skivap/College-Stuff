#include <stdio.h>
int function(int x){
    if(x>=1000) return x-2;
    else{
        printf("%d\n", x);
        return function(function(x+5));}
}
int main(){
    int x = 12;
    printf("%d\n", function(x));
}