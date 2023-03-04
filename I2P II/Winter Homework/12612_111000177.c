//12612 - Queries on a String   
#include <stdio.h>
#include <string.h>
int main(){
    char str1[10001];
    char str2[10001];
    scanf("%s", str1);
    strcpy(str2, str1);
    int size = strlen(str1);
    int t;
    scanf("%d", &t);
    int l,r,k, pos, len;
    while(t--){
        scanf("%d%d%d", &l, &r, &k);
        k = k%(r-l+1);
        for(int i=0;i<=size;i++){
            if(i<l-1 || i>= r) str2[i] = str1[i];
            else{
                pos = i - k;
                if(pos< l-1) pos += (r-l+1);
                str2[i] = str1[pos];
            }
        }
        strcpy(str1, str2);
    }
    printf("%s\n", str1);
    
}