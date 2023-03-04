//DOMO TRAVELS AROUND THE WORLD

#include <stdio.h>
int city[100];
int teleport[100][100];
int result = 0;
int n;
void function(int x){
    city[x] = 1;
    for(int i=0;i<n;i++){
        if(city[i]==1) continue;
        if(teleport[x][i]==1) function(i);
    }
    if(x==0){
        for(int i=0;i<n;i++){
            if(city[i] == 0){
                function(i);
                result++;
            }
        }
    }
}
int main(){
    int testcase, temp1, temp2;
    scanf("%d %d", &n, &testcase);
    while(testcase--){
        scanf("%d %d", &temp1, &temp2);
        teleport[temp1][temp2] = 1;
        teleport[temp2][temp1] = 1;
    }
    function(0);
    printf("%d\n", result);
}