#include <stdio.h>
#include <string.h>

int function(char *, int, int);
int valid(char *, int, int);
int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        char str[50];
        scanf("%s", str);
        printf("%d\n", function(str, 0, strlen(str)));
    }
}

int function(char *str, int start, int size){
    if(start>=size) return 1;
    int sum = 0;
    for(int i = start;i<size;i++){
        if(valid(str, start, i)){
            sum += function(str, i+1, size);
        }
    }
    return sum;
}

int valid(char *str, int start, int end){
    while(start<end){
        if(str[start]!=str[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}