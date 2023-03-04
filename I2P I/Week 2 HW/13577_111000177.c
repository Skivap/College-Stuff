#include <stdio.h>
char convert(char x);

int main(){
    char a,b,c,d,e;
    scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);
    a = convert(a);
    b = convert(b);
    c = convert(c);
    d = convert(d);
    e = convert(e);
    printf("%c%c%c%c%c\n",a,b,c,d,e);

}
char convert(char x){
    x = x - 32;
    x = 155-x;
    return x;
}