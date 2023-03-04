#include <stdio.h>
int todo(int x, int y);
int main(){
    char ch[1000];
    char output;
    float length, length_zip;
    while(scanf("%s",ch)!=EOF){
        int streak = 0;
        char temp = 0;
        length = 0;
        length_zip=0;
        for(int i=0; ch[i]!='\0';i++){
            length++;
            if(i==0){
                temp = ch[i];
                streak++;
            }else{
                if(ch[i+1]=='\0'){
                    if(ch[i]==temp){
                        length_zip += todo(streak+1, temp);
                    }else{
                        length_zip += todo(streak, temp);
                        temp = ch[i];
                        streak = 1;
                        length_zip += todo(streak, temp);
                    }
                }else if(ch[i]==temp){
                    streak++;
                }else{
                    length_zip += todo(streak, temp);
                    temp = ch[i];
                    streak = 1;
                }
            }
        }
        printf("\n");
        if(length_zip<length){
            float result = length_zip/length;
            printf("compress rate:%6.3f\n",result);
        }else{
            printf("the string can't zip\n");
        }
    }
}

int todo(int x, int y){
    int z;
    if(y<60){
        printf("%d'%c'",x, y);
        z = 3;
    }else{
        printf("%d%c",x, y);
        z = 1;
    }
    while(x>0){
        z++;
        x=x/10;
    }
    return z;
}