/* strtok example */
#include <stdio.h>
#include <string.h>

int main (){
    char input[5001];
    char *ptr;
    char folder[50][5001];
    char decode[50][5001];
    int test, check;
    int folder_i, decode_i;
    scanf("%d", &test);
    while(test--){
        int valid = 1;
        //SCANNING
        scanf("%s", input);
        ptr = strtok(input,"/");
        folder_i = 0;
        while(ptr!=NULL){
            strcpy(folder[folder_i], ptr);
            folder_i++;
            ptr = strtok(NULL, "/");
        }
        scanf("%s", input);
        ptr = strtok(input,"/");
        decode_i = 0;
        while(ptr!=NULL){
            strcpy(decode[decode_i], ptr);
            decode_i++;
            ptr = strtok(NULL, "/");
        }
        
        //CHECKING
        int check[50] = {0};
        int streak = 0;
        for(int i=0;i<decode_i;i++){
            for(int j=0;j<folder_i;j++){
                if(strcmp(decode[i], folder[j])==0){
                    check[i] = 1;
                }
            }
        }
        for(int i=0;i<folder_i;i++){
            if(check[i]==1){
                streak++;
            }
            else if(streak>0 && check[i]==0){
                break;
            }
        }
        if(streak == decode_i)printf("valid\n");
        else printf("not valid\n");
    }
}