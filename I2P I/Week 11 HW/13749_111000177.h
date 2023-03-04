#include <stdlib.h>
#include <string.h>
char **split_(char* str, char* pattern, int* split_num){
    char ** arr;
    arr = (char**)malloc(200*sizeof(char*));
    for(int i=0;i<200;i++) arr[i] = (char*)malloc(500*sizeof(char));
    int n = strlen(pattern);
    int x = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int valid;
    while(str[x]!='\0'){
        if(str[x]!=pattern[0]){
            arr[i][j] = str[x];
            j++;
        }
        else{
            valid = 1;
            for(k=0;k<n;k++){
                if(str[x+k]!=pattern[k]){
                    valid = 0;
                    break;
                }
            }
            if(valid){
                arr[i][j] = '\0';
                if(j!=0){
                    i++;
                    j = 0;
                }
                x += n-1;
            }else{
                arr[i][j] = str[x];
                j++;
            }
        }
        x++;
    }
    *split_num = i+1;
    return arr;
}

/*
goodotmorningot!
ot

good
morning
!
*/
void free_(char **result, int split_num){

}
