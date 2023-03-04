//Happy B to As with Weeheehea

#include <stdio.h>
char solution[3][3];
int solution_count;
int startx, starty, test, flag;
int result = 0;

void solve(char (*arr)[3][3], int moves, int x, int y, int direction){
    for(int a=test-1;a>=0;a--){
        if(solution[x][y]==arr[a][x][y]){
            flag = 0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(arr[a][i][j]==solution[i][j]) flag++;
                }
            }
            if(flag==9){
                result++;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        arr[a][i][j]=arr[test-1][i][j];
                    }
                }
                test--;
            }
        }
    }
    if(moves>0){
        if(x>0 && direction!=3){
            solution[x][y] = solution[x-1][y];
            solution[x-1][y] = 'x';
            solve(arr, moves-1, x-1, y, 1);
            solution[x-1][y] = solution[x][y];
            solution[x][y] = 'x';
        }
        if(y>0 && direction!= 4){
            solution[x][y] = solution[x][y-1];
            solution[x][y-1] = 'x';
            solve(arr, moves-1, x, y-1, 2);
            solution[x][y-1] = solution[x][y];
            solution[x][y] = 'x';
        }
        if(x<2 && direction!=1){
            solution[x][y] = solution[x+1][y];
            solution[x+1][y] = 'x';
            solve(arr, moves-1, x+1, y, 3);
            solution[x+1][y] = solution[x][y];
            solution[x][y] = 'x';
        }
        if(y<2 && direction!=2){
            solution[x][y] = solution[x][y+1];
            solution[x][y+1] = 'x';
            solve(arr, moves-1, x, y+1, 4);
            solution[x][y+1] = solution[x][y];
            solution[x][y] = 'x';
        }
    }
}

int main(){
    int move;
    scanf("%d %d", &test, &move);
    char arr[test][3][3];
    for(int a=0;a<test;a++){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                scanf(" %c", &arr[a][i][j]);
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf(" %c", &solution[i][j]);
            if(solution[i][j]==1) solution_count++;
            else if(solution[i][j]=='x'){
                startx = i;
                starty = j;
            }
        }
    }
    solve(arr, move, startx, starty, 0);
    printf("%d\n", result);
}