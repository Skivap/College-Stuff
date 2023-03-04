#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, temp;
    int solution = 0;
    scanf("%d %d", &n, &k);
    int *check = malloc(k*sizeof(int));
    long long int sum = 0;
    long long int verify = k*(k+1)/2;
    for(int i=1;i<=n;i++){
        scanf("%d", &temp);
        sum -= check[temp-1];
        check[temp-1] = i;
        sum += check[temp-1];
        if(i>=k){
            if(sum==verify) 
                solution++;
            verify += k;
        }
    }
    free(check);
    printf("%d\n", solution);
}