    #include <stdio.h>
    int main(){
        int x, y;
        scanf("%d", &x);
        int image[x][x];
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                scanf("%d",&image[i][j]);
            }
        }
        scanf("%d", &y);
        int scanner[y][y];
        for(int i=0;i<y;i++){
            for(int j=0;j<y;j++){
                scanf("%d",&scanner[i][j]);
            }
        }
        int count = 0;
        int check1, check2;
        for(int i=0;i<=x-y;i++){
            for(int j=0;j<=x-y;j++){
                check1 = 0;
                check2 = 0;
                for(int k=0;k<y;k++){
                    for(int l=0;l<y;l++){
                        if(scanner[k][l]==1){
                            check1++;
                            if(image[i+k][j+l]==1){
                                check2++;
                            }
                        }
                    }
                }
                if(check1==check2){
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }