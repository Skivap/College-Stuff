#include <stdio.h>
int main(){
    char name[10001];
    int backspace[100000] = {0};
    int health;
    scanf("%s", name);
    scanf("%d", &health);
    char ch;
    int streak = 0;
    int i = 0;
    ch = getchar();
    while((ch=getchar())!=EOF){
        if(ch == '!'||ch=='/'||(ch>='A' && ch <= 'z')){
            if(ch == name[streak] && streak == i){
                streak++;
                backspace[i] = streak;
                printf("%d\n", streak);
                if(name[streak]=='\0'){
                    printf("DAISUKI!\n");
                    return 0;
                }
            }
            else if(ch == '/'){
                streak = backspace[i-2];
                i--;
                health--;
                if(health<=0){
                    printf("SAYONARA\n");
                    return 0;
                }
                if(i<=0){
                    i = 0;
                    streak = 0;
                }
                continue;

            }else if(ch == '!'){
                health = health - 2;
                i = 0;
                streak = 0;
                if(health<=0){
                    printf("SAYONARA\n");
                    return 0;
                }
                continue;
            }else{
                streak = 0;
                backspace[i]=0;
                printf("no\n");
            }
            i++;
        }
    }
    return 0;
}