//12604 - N-Queens M-Rooks Problem
#include <stdio.h>
int total, max;
int pos[10];
char piece[10];
int valid(int row, int col){
    int v = 2;
    for(int i=0;i<row;i++){
        if(col==pos[i]) return 0;
        if(col - row + i == pos[i]){
            if(piece[i]=='R') v = 1;
            else return 0;
        }
        if(col + row - i == pos[i]){
            if(piece[i]=='R') v = 1;
            else return 0;
        }
    }
    return v;
}
void function(int queen, int rook, int row){
    if(row==max){
        total++;
        return;
    }
    for(int i=0;i<max;i++){
        int v = valid(row, i);
        if(v==2 && queen>0){
            pos[row] = i;
            piece[row] = 'Q';
            function(queen-1, rook, row+1);
        }
        if(v > 0 && rook>0){
            pos[row] = i;
            piece[row] = 'R';
            function(queen, rook-1, row+1);
        }
    }
}
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF){
        total = 0;
        max = n+m;
        function(n, m, 0);
        printf("%d\n", total);
    }
}