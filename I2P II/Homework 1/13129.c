#include <stdio.h>
#include <stdlib.h>
#include "13129_111000177.h"


int main(){

    int n, k;

    while(scanf("%d%d", &n, &k)!=EOF){
        head = createList(n);
        solveJosephus(n, k);
    }

    return 0;
}