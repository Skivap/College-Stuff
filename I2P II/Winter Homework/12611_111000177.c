//12611 - The Same Calendar   
#include <stdio.h>
int isLeapYear(int x){
    if(x%400==0) return 1;
    if(x%100==0) return 0;
    if(x%4==0) return 1;
    return 0;
}
int main(){
    int t;
    scanf("%d", &t);
    int ori, num;
    int modu = 0;
    while(t--){
        scanf("%d", &ori);
        num = ori;
        while(1){
            if(num!=ori && modu%7==0 && (isLeapYear(ori)==isLeapYear(num))) break;
            if(isLeapYear(num)) modu += 2;
            else modu += 1;
            num++;
        }
        printf("%d\n", num);
    }
}