#include <stdio.h>
int arr[14]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};
void carpet(int x, int y, int n){
    if(n==1){
        if(x%3 != 1 || y%3 != 1){
            printf(" ");
            return;
        }else{
            printf("*");
            return;
        }
    }
    int pattern = arr[n-1] *3;
    int mulai = arr[n-1]-1;
    if(x%pattern>mulai && x%pattern<=mulai+arr[n-1]){
        if(y%pattern>mulai && y%pattern<=mulai+arr[n-1]){
            printf("*");
            return;
        }else{
            carpet(x,y,n-1);
            return;
        }
    }else{
        carpet(x,y,n-1);
        return;
    }

}
int main()
{
    int x;
    scanf("%d", &x);
    for(int i=1; i<=arr[x-1]*3-2; i++){
        for(int j=1; j<=arr[x-1]*3-2; j++){
            carpet(i, j, x);
        }
        printf("\n");
    } 
}