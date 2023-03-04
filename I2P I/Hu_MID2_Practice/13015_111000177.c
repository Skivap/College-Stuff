//PORTAL MAZE

#include <stdio.h>
int solution, n, m;
char arr[301][301];
int teleport[26][2];

int teleport_x[26];
int teleport_y[26];

void pathfinding(int x, int y){
    if(x<0||y<0||x>=n||y>=m) return;
    else if(arr[x][y]=='#') return;
    else if(arr[x][y]=='&') solution = 1;
    else if(arr[x][y]>='a'&&arr[x][y]<='z') pathfinding(teleport[arr[x][y]-'a'][0],teleport[arr[x][y]-'a'][1]);
    else{
        arr[x][y] = '#';
        pathfinding(x+1, y);
        pathfinding(x-1, y);
        pathfinding(x, y+1);
        pathfinding(x, y-1);
    }
}

int main(){
    int test, startx, starty;
    scanf("%d", &test);
    while(test--){
        solution = 0;
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c", &arr[i][j]);
                if(arr[i][j]=='$'){
                    startx = i;
                    starty = j;
                }
                else if(arr[i][j]>='A'&&arr[i][j]<='Z'){
                    teleport[arr[i][j]-'A'][0] = i;
                    teleport[arr[i][j]-'A'][1] = j;
                }
            }
        }
        pathfinding(startx, starty);
        if(solution) printf("Yes\n");
        else printf("No\n");

    }
}