#include <stdio.h>
long long int length[51];
void function(long long int start, long long int end, int k){
    if(start<0) start = 0;
    if(end>=length[k]) end = length[k] - 1;
    if(k==1){
        if(start==0 && end>=0) printf("O");
        if(start<=1 && end>=1) printf("u");
        if(start<=2 && end>=2) printf("Q");
    }else{
        if(end<0) return;
        if(start==0)printf("O");
        start--;
        end--;
        if(end<0) return;
        if(start<length[k-1])function(start,end, k-1);
        start -= length[k-1];
        end -= length[k-1];
        if(end<0) return;
        if(start<=0)printf("u");
        start--;
        end--;
        if(end<0) return;
        if(start<length[k-1])function(start,end, k-1);
        start -= length[k-1];
        end -= length[k-1];
        if(end<0) return;
        if(start<=0)printf("Q");
    }
}
int main(){
    length[1] = 3;
    for(int i=2;i<=50;i++){
        length[i] = length[i-1]*2 + 3;
    }
    long long int b,c;
    int a;
    while(scanf("%d%lld%lld",&a,&b,&c)!=EOF){
        function(b,c, a);
        printf("\n");
    }
}