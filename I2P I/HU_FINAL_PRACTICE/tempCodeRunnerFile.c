#include <stdio.h>
#include <string.h>

int main(){
    int test;
    long long int x;
    int streak, longest, count;
    scanf("%d", &test);
    while(test--){
        scanf("%lld", &x);
        streak = 0; longest = 0; count = 0;
        while(x!=0){
            if(x%2==1){
                count++;
                if(streak>longest) longest = streak;
                streak = 0;
            }
            if(x%2==0 && count>0){
                streak++;
            }
            x = x/2;
        }
        if(count<2) printf("-1\n");
        else printf("%d\n", longest);
    }
}