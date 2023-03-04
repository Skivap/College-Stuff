//12603 - Launch of Collider   
#include <stdio.h>
int main(){
    int t;
    int shortest = -2;
    scanf("%d", &t);
    char arr[t];
    int val[t];
    for(int i=0;i<t;i++)
        scanf(" %c", &arr[i]);
    for(int i=0;i<t;i++){
        scanf("%d", &val[i]);
        if(i>0 && arr[i]=='L' && arr[i-1] == 'R')
            if(shortest == -2 || val[i]-val[i-1]<shortest)
                shortest = val[i]- val[i-1];
    }
    printf("%d\n", shortest/2);
}