#include <stdlib.h>
#include <stdio.h>
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned ***array = malloc(sizeof(unsigned **) * n + sizeof(unsigned *) * n * m + sizeof(unsigned) * n * m * k);
    for(int i = 0; i < n; i++){
        array[i] = ((unsigned**)(array + n))+ m*i;
        for(int j=0; j<m;j++){
            array[i][j] = ((unsigned*)(array + n + m*n)) + i*m*k + j*k;
        }
    }
    return array;
}
void delete_3d_array(unsigned ***arr){
    free(arr);
}