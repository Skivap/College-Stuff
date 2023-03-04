#include <stdio.h>
int main(){
    float g, b, s;
    scanf("%f %f %f",&g,&b,&s);
    long int a = g*b;
    float c = g/s;
    printf("%ld\n",a);
    printf("%.2f\n",c);
}