#include <stdio.h>
int main(){
    int x,y,min,max, largest, number, temp1, temp2;
    scanf("%d", &x);
    int customer[x];
    for(int i=0;i<x;i++){
        scanf("%d", &customer[i]);
    }
    scanf("%d", &y);
    for(int i=0;i<y;i++){
        scanf("%d %d", &min,&max);
        min -= 1;
        max -= 1;
        largest = customer[min];
        number = 0;
        for(int j=min;j<=max;j++){
            temp1 = 0;
            for(int k=j+1; k<=max;k++){
                if(customer[j]==customer[k]){
                    temp1 +=1;
                }
            }
            if(number<temp1){
                largest = customer[j];
                number = temp1;
            }
            if(number == temp1 && customer[j]<largest){
                largest = customer[j];
            }
        }
        printf("%d\n", largest);
    }
}