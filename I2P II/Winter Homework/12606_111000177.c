//12606 - Happy New Year
#include <stdio.h>

int main(){
    int min, max, t, val;
    int num;
    scanf("%d", &t);
    for(int i=0;i<=t;i++){
        scanf("%d", &num);
        if(i==0){
            min = num;
            max = num;
        }else{
            if(num<min) min = num;
            if(num>max) max = num;
        }
    }
    printf("%d\n", (max-min)*2);
}