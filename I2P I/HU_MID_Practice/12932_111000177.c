#include <stdio.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    char arr[x][y];
    for(int i=0; i<x; i++){
        scanf("%s", arr[i]);
    }
    int test;
    int temp;
    scanf("%d", &test);
    for(int i=0;i<test;i++){
        scanf("%d", &temp);
        temp--;
        for(int j=0;j<x;j++){
            if(arr[j][temp]=='/'){
                if(temp==0){
                    temp = -1;
                    break;
                }else if(arr[j][temp-1]=='\\'){
                    temp = -3;
                    break;
                }else{
                    temp -= 1;
                }
            }
            if(arr[j][temp]=='\\'){
                if(temp==y-1){
                    temp = -2;
                    break;
                }else if(arr[j][temp+1]=='/'){
                    temp = -3;
                    break;
                }else{
                    temp += 1;
                }
            }
        }
        if(temp==-1){
            printf("Left!\n");
        }else if(temp == -3){
            printf("Stuck QQ\n");
        }else if(temp == -2){
            printf("Right!\n");
        }else{
            printf("Position: %d\n", temp+1);
        }
    }
}
//////////