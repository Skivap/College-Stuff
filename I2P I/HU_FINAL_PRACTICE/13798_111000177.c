#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int max1, max2;
int max(int a, int b){
    if(a>b)return a;
    else return b;
}
int compare(char *str1, char *str2, int a, int b, int**dp){
    if(a==max1||b==max2) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    if(str1[a]==str2[b]) return dp[a][b] = compare(str1, str2, a+1, b+1, dp) + 1;
    else return dp[a][b] = max(compare(str1, str2, a+1, b, dp), compare(str1, str2, a, b+1, dp));
}
int main(){
    char str1[3101];
    char str2[3101];
    scanf("%s %s", str1, str2);
    max1 = strlen(str1);
    max2 = strlen(str2);
    int **dp = malloc(max1*sizeof(int*));
    for(int i=0;i<max1;i++) {
        dp[i] = malloc(max2*sizeof(int));
        for(int j=0;j<max2;j++) dp[i][j] = -1;
    }
    printf("%d\n", compare(str1, str2, 0, 0, dp));
}