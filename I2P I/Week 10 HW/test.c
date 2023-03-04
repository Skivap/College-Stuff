#include<stdio.h>
int n,m;

int solve(int n, int m){
    int count=0;
    while(m!=n){
        m>>=1;
        n>>=1;
        count++;
        printf("%d %d %d\n", m, n, count);
    }
    return m<<count;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n,&m);
        printf("%d\n",solve(n,m));
    }
    return 0;
}