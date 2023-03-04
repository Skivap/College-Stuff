#include <stdio.h>
int powerof(a,b){
    int hasil = a;
    for(int j=1;j<b;j++){
        hasil = hasil*a;
    }
    if(b == 0){
        hasil = 1;
    }
    return hasil;
}
int main(){
    int x;
    while(scanf("%d", &x) !=EOF){
        int y = x;
        int digit = 0;
        int number[32];
        int sum = 0;
        while(x!=0){
            number[digit] = x%10;
            x = x/10;
            digit += 1;

        }
        for(int i=0;i<digit;i++){
            sum += powerof(number[i],digit);
        }
        if (sum == y){
            printf("Yes it is.\n");
        }else{
            printf("No it is not.\n");
        }
        
    }
}