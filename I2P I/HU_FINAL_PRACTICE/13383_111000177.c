//13383	Cardcaptor Sakura2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int size[10];
int a, b, c;
void print(int** arr){
    for(int i=0;i<10;i++){
        printf("%d:", i);
        if(size[i]==0)printf(" No card");
        else{
            for(int j=0;j<size[i];j++){
                printf(" %d", arr[i][j]);
            }
        }
        printf("\n");
    }
}
void all(int** arr){
    scanf("%d %d", &a, &b);
    for(int i=0;i<10;i++){
        for(int j=0;j<b;j++) arr[i][j] = a;
        size[i] = b;
    }
}
void place(int** arr){
    scanf("%d %d", &a, &b);
    size[a] = b;
    for(int i=0;i<b;i++){
        scanf("%d", &c);
        arr[a][i] = c;
    }
}
void swap(int** arr){
    scanf("%d %d", &a, &b);
    int *temp = arr[a];
    int temp1 = size[a];
    arr[a] = arr[b];
    size[a] = size[b];
    arr[b] = temp;
    size[b] = temp1;
}
void clear(int** arr){
    for(int i=0;i<10;i++)
        size[i] = 0;
}
void shiftleft(int** arr){
    int * temp = arr[0];
    int temp1 = size[0];
    for(int i=0;i<9;i++){
        arr[i] = arr[i+1];
        size[i] = size[i+1];
    }
    size[9] = temp1;
    arr[9] = temp;
}
void shiftright(int** arr){
    int * temp = arr[9];
    int temp1 = size[9];
    for(int i=9;i>0;i--){
        arr[i] = arr[i-1];
        size[i] = size[i-1];
    }
    size[0] = temp1;
    arr[0] = temp;
}

int main(){
    char input[20];
    int** arr = (int**)malloc(10*sizeof(int*));
    for(int i=0;i<10;i++) arr[i] = (int*)malloc(10000*sizeof(int));
    while(1){
        scanf("%s", input);
        if(strcmp(input, "exit")==0) break;
        if(strcmp(input, "print")==0) print(arr);
        if(strcmp(input, "all")==0) all(arr);
        if(strcmp(input, "place")==0) place(arr);
        if(strcmp(input, "swap")==0) swap(arr);
        if(strcmp(input, "clear")==0) clear(arr);
        if(strcmp(input, "shiftleft")==0) shiftleft(arr);
        if(strcmp(input, "shiftright")==0) shiftright(arr);
    }
    for(int i=0;i<10;i++) free(arr[i]);
    free(arr);
    return 0;
}