#include <stdio.h>
int main(){
    int x, y, n, S;
    scanf("%d %d %d %d", &n, &S, &x, &y);
    char arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    int con = 1;
    char temp;
    int tempx, tempy;
    for(int i=0;i<=S;i++){
        printf("%c", arr[x][y]);
        temp = (con==1)?123:0;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                if(a==0 && b==0){
                    continue;
                }
                if((x+a)<n && (y+b)<n && x+a>=0 && y+b>=0){
                    if(arr[x+a][y+b]==temp){
                        tempx = a;
                        tempy = b;
                    }
                    if(con==1){
                        if(arr[x+a][y+b]<temp){
                            tempx = a;
                            tempy = b;
                            temp = arr[x+a][y+b];
                        }
                    }else{
                        if(arr[x+a][y+b]>temp){
                            tempx = a;
                            tempy = b;
                            temp = arr[x+a][y+b];
                        }
                    }
                }
            }
        }
        if(temp=='a'||temp=='f'||temp=='k'||temp=='p'||temp=='E'||temp=='J'||temp=='O'||temp=='T'){
            y--;
        }else
        if(temp=='b'||temp=='g'||temp=='l'||temp=='q'||temp=='D'||temp=='I'||temp=='N'||temp=='S'){
            y++;
        }else
        if(temp=='c'||temp=='h'||temp=='m'||temp=='r'||temp=='C'||temp=='H'||temp=='M'||temp=='R'){
            x--;
        }else
        if(temp=='d'||temp=='i'||temp=='n'||temp=='s'||temp=='B'||temp=='G'||temp=='L'||temp=='Q'){
            x++;
        }else
        if(temp=='e'||temp=='j'||temp=='o'||temp=='t'||temp=='A'||temp=='F'||temp=='K'||temp=='P'){
            x = x+tempx;
            y = y+tempy;
            con=(con==1)?0:1;
        }else{
            x = x+tempx;
            y = y+tempy;
        }
        if(x>=n || y>=n || y<0 || x<0){
            break;
        }
    }  
}