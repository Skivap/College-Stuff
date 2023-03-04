#include <stdio.h>
#include <math.h>

int number(int n, int x, int swap){
    //printf("%d %d %d\n", n, x, swap);
    if(n==0){
        if(swap==-1) return 1;
        else return 0;
    }
    if(x==(pow(2,n)-1)){
        if(swap == -1) return 0;
        else return 1;
    }
    else if(x<pow(2,n)-1){
        return number(n-1, x, swap);
    }else{
        x = pow(2, n+1) - 2 - x;
        return number(n-1, x, swap*-1);
    }
}
int main(){
    int n, t, temp, solution;
    scanf("%d %d", &n, &t);
    while(t--){
        scanf("%d", &temp);
        printf("%d\n", number(n, temp, 1));
    }

}