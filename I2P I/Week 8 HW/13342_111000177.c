#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursive(){
    char ch;
    int num;
    ch = getchar();
    if(ch==' '){
        recursive();
        return;
    }
    if(ch == '+'){
        recursive();
        printf(" ");
        recursive();
        printf(" ");
        printf("+");
    }
    if(ch =='-'){
        recursive();
        printf(" ");
        recursive();
        printf(" ");
        printf("-");
    }
    if(ch =='*'){
        recursive();
        printf(" ");
        recursive();
        printf(" ");
        printf("*");
    }
    if(ch =='/'){
        recursive();
        printf(" ");
        recursive();
        printf(" ");
        printf("/");
    }
    if(ch >='0'&& ch<='9'){
        ungetc(ch, stdin);
        scanf("%d", &num);
        printf("%d", num);
    }
}
int main(){
    recursive();
    return 0;
}