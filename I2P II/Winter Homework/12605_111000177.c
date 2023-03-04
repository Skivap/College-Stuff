//12605 - Rebranding   
#include <stdio.h>

int main(){
    int len, t;
    int x, y;
    scanf("%d %d", &len, &t);
    len++;
    char str[len];
    scanf("%s", str);
    char alph[26];
    for(int i=0;i<26;i++)
        alph[i] = 'a'+i;
    char a, b;
    while(t--){
        scanf(" %c %c", &a, &b);
        if(a==b) continue;
        for(int i=0;i<26;i++){
            if(alph[i]==a) x = i;
            if(alph[i]==b) y = i;
        }
        alph[x] = b;
        alph[y] = a;
    }
    for(int i=0;i<len-1;i++){
        printf("%c", alph[str[i]-'a']);
    }
    printf("\n");
}