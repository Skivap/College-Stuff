#include <stdio.h>
int arr[9][9];
int result = 0;
void next(int x, int y);
void sudoku(int x, int y);
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    sudoku(0,0);
    if(result == 0){
        printf("no solution\n");
    }
}
void next(int x, int y){
    if(x==8 && y == 8 && result == 0){
        result = 1;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                printf(j<8?"%d ":"%d\n", arr[i][j]);
        return;
    }
    if(y==8){
        sudoku(x+1, 0);
        return;
    }
    sudoku(x,y+1);
}
void sudoku(int x, int y){

    if(result == 0){
        if(arr[x][y] != 0){
            next(x, y);
            return;
        }
        for(int number=1;number<=9;number++){
            int valid = 1;
            for(int i=0;i<9;i++){
                if(arr[x][i]==number || arr[i][y]==number){
                    valid = 0;
                }
            }
            for(int i=(x/3)*3;i<(x/3)*3+3;i++){
                for(int j=(y/3)*3;j<(y/3)*3+3;j++){
                    if(arr[i][j]==number){
                        valid = 0;
                    }
                }
            }
            if(valid){
                arr[x][y] = number;
                next(x,y);
                arr[x][y] = 0;
            }
        }
    }
}