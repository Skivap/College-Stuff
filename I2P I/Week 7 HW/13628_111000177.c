#include <stdio.h>
int arr[410][410];
int middle[8] = {0,1};
int cumulative[8] = {0,1};
void initialize_size() {

    for(int i = 2; i <= 7; i++) {

        middle[i] = 4 * cumulative[i-2] - middle[i-2] + 2;

        cumulative[i] = cumulative[i-1] + middle[i];

    }

}
int snowflake_size(int order) {
    if(order==0){
        return 0;
    }
    return cumulative[order] + cumulative[order - 1];
}
void snowflake(int n, int x, int y){
    if(n==0){
        return;
    }
    if(n==1){
        arr[x][y]=1;
        return;
    }
    for(int i=x+cumulative[n-1];i<x+cumulative[n];i++){
        for(int j=y+cumulative[n-1];j<y+cumulative[n];j++){
            arr[i][j] = 1;
        }
    }
    snowflake(n-1, x, y);
    snowflake(n-1, x, y+snowflake_size(n-1)+snowflake_size(n-2)+2);
    snowflake(n-1, x+snowflake_size(n-1)+snowflake_size(n-2)+2, y+snowflake_size(n-1)+snowflake_size(n-2)+2);
    snowflake(n-1, x+snowflake_size(n-1)+snowflake_size(n-2)+2, y);

    snowflake(n-2, x+snowflake_size(n-1)+1, y+snowflake_size(n-2)+1);
    snowflake(n-2, x+snowflake_size(n-2)+1, y+snowflake_size(n-1)+1);
    snowflake(n-2, x+snowflake_size(n-1)+1, y+cumulative[n]-cumulative[n-3]);
    snowflake(n-2, x+cumulative[n]-cumulative[n-3], y+snowflake_size(n-1)+1);
}
int main(){
    initialize_size();
    int x;
    scanf("%d", &x);
    snowflake(x, 0, 0);
    for(int i=0;i<snowflake_size(x);i++){
        for(int j=0;j<snowflake_size(x);j++){
            if(arr[i][j]==1){
                printf("#");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}