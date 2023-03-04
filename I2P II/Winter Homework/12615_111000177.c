//12615 - Knight Search  
#include <stdio.h>

char str[10] = "ICPCASIASG";
int n;
char map[100][100];
int valid = 0;
void jump(int i, int j, int step){
    if(valid) return;
    if(i<0 || j<0 || i>=n || j >=n) return;
    if(step==9 && map[i][j]=='G') valid = 1;
    else if(map[i][j]==str[step]){
        jump(i+2,j+1,step+1);
        jump(i+1,j+2,step+1);
        jump(i-2,j+1,step+1);
        jump(i-1,j+2,step+1);
        jump(i+2,j-1,step+1);
        jump(i+1,j-2,step+1);
        jump(i-2,j-1,step+1);
        jump(i-1,j-2,step+1);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf(" %c", &map[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(map[i][j]=='I')
                jump(i,j,0);
    if(valid)printf("YES\n");
    else printf("NO\n");
}