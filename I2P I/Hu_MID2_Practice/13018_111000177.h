//DIAGONAL SORTING

void array2d_sort(int row, int col, long long arr[][500]){
    long long temp;
    int k;
    for(int i=0;i<row;i++){
        int j = 1;
        while(i+j<row && j<col){
            k = j;
            temp = arr[i+k][k];
            k--;
            while(k>=0 && arr[i+k][k]>temp){
                arr[i+k+1][k+1] = arr[i+k][k];
                k--;
            }
            arr[i+k+1][k+1] = temp;
            j++;
        }
    }
    for(int i=1;i<col;i++){
        int j = 1;
        while(i+j<col && j<row){
            k = j;
            temp = arr[k][k+i];
            k--;
            while(k>=0 && arr[k][k+i]>temp){
                arr[k+1][i+k+1] = arr[k][i+k];
                k--;
            }
            arr[k+1][i+k+1] = temp;
            j++;
        }
    }
}