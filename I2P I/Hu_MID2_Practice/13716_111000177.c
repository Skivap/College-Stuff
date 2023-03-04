//SEBASTIAN DOMO

#include <stdio.h>
int n, m, min, min_player, temp, solution, domo;
char arr[20][20];
int player[4][2];
void pathfinding(int x, int y, int step){
    if(x<0||y<0||x>=n||y>=m) return;
    if(arr[x][y]=='X') return;
    if(arr[x][y]=='-'){
        if(solution==0) temp = step;
        else if(step<temp) temp = step;
        solution = 1;
        return; 
    }
    arr[x][y] = 'X';
    pathfinding(x+1,y,step+1);
    pathfinding(x-1,y,step+1);
    pathfinding(x,y+1,step+1);
    pathfinding(x,y-1,step+1);
    arr[x][y] = '.';
}

int main(){
    int test, temp1, temp2;
    scanf("%d %d %d", &n, &m, &test);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    for(int i=0;i<=test;i++){
        temp = 0, solution = 0;
        scanf("%d %d", &temp1, &temp2);
        pathfinding(temp1, temp2, 0);

        if(i==test)printf("%d\n", temp);
        else printf("%d ", temp);
        if(i==0){
            domo = temp;
        }else {
            if(i==1){
                min = temp;
                min_player = 0;
            }else{
                if(temp<min){
                    min = temp;
                    min_player = i;
                }
            }
        }
    }
    printf("%d\n", min - domo);
}
