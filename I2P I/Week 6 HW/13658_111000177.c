#include <stdio.h>
void pathfinding(int n, int m, int (*arr)[m], int x, int y, int step){
    arr[x][y] = step;
    if(x-1>=0){
        if(arr[x-1][y] > arr[x][y] || arr[x-1][y]==-2){
            pathfinding(n, m, arr, x-1, y, step + 1);
        }
    }
    if(x+1<n){
        if(arr[x+1][y] > arr[x][y] || arr[x+1][y]==-2){
            pathfinding(n, m, arr, x+1, y, step + 1);
        }
    }
    if(y-1>=0){
        if(arr[x][y-1] > arr[x][y-1] || arr[x][y-1]==-2){
            pathfinding(n, m, arr, x, y-1, step + 1);
        }
    }
    if(y+1<m){
        if(arr[x][y+1] > arr[x][y] || arr[x][y+1]==-2){
            pathfinding(n, m, arr, x, y+1, step + 1);
        }
    }
    return;
}
int main(){
    int n, m, startx, starty, endx, endy;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    char temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c", &temp);
            if(temp=='S'){
                startx = i;
                starty = j;
            }
            if(temp=='o'||temp=='^'){
                arr[i][j] = -1;
                continue;
            }
            if(temp=='M'){
                endx = i;
                endy = j;
            }
            arr[i][j] = -2;
        }
    }
    pathfinding(n, m, arr, startx, starty, 0);
    printf("%d\n", arr[endx][endy]);
    return 0;
}

    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==-1){
                printf("# ");
                continue;
            }else{
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
    */