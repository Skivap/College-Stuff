#include <stdio.h>
#include <string.h>

int n;
long long int sum;
int solution = 0;
long long int answer = 0;
long long int answer2 = 0;
int cols[11];
long long int arr[11][11];
int valid(int row, int col){
    for(int i=0;i<row;i++){
        if(col-row+i==cols[i]) return 0;
        if(col+row-i==cols[i]) return 0;
        if(col==cols[i]) return 0;
    }
    return 1;
}
void solve(int row){
    if(row==n){
        if(solution<2){
            solution++;
            sum = 0;
            for(int i=0;i<n;i++) sum += arr[i][cols[i]];
            if(solution==1) answer = sum;
            else{
                if(sum==answer) solution--;
                else if(sum>answer){
                    answer2 = answer;
                    answer = sum;
                }else answer2 = sum;
            }
        }else{
            sum = 0;
            for(int i=0;i<n;i++) sum += arr[i][cols[i]];
            if(sum>answer){
                answer2 = answer;
                answer = sum;
            }else if(sum==answer) return;
            else if(sum>answer2) answer2 = sum;
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(valid(row, i)){
            cols[row] = i;
            solve(row+1);
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lld", &arr[i][j]);
    solve(0);
    if(solution>1) printf("%lld\n", answer2);
    else printf("Invalid\n");
}