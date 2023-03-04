#include <stdio.h>
int main(){
    int x, y, temp;
    int streak = 0;
    scanf("%d %d", &x, &y);
    //UP RIGHT = LEFT DOWN
    // UP LEFT = RIGHT DOWN
    while(x>0){
        int vertical[2048]={0};
        int horizontal[2048]={0};
        int diagonal_up_right[2048]={0};
        int diagonal_up_left[2048]={0};
        int diagonal_left_down[2048]={0};
        int diagonal_right_down[2048]={0};
        int star = 0;
        for(int i=0;i<y;i++){
            for(int j=0;j<y;j++){
                scanf("%d", &temp);
                if(temp==255){
                    streak++;
                    vertical[j]++;
                    if(i<=j){
                        diagonal_up_right[j-i]++;
                    }else{
                        diagonal_left_down[i-j]++;
                    }
                    if(i+j<y){
                        diagonal_up_left[i+j]++;
                    }else{
                        diagonal_right_down[i+j-y+1]++;
                    }
                }
            }
            if(streak==y){
                horizontal[i]=y;
            }
            streak=0;
        }
        for(int i=0;i<y;i++){
            for(int j=0;j<y;j++){
                if(horizontal[i]==y && vertical[j]==y){
                    if((i<=j && diagonal_up_right[j-i]==y-(j-i))||(i>j && diagonal_left_down[i-j]==y-(i-j))){
                        if(i+j<y && diagonal_up_left[i+j]==i+j+1){
                            star++;
                        }else if(i+j>=y && diagonal_right_down[i+j-y+1]==y*2-1-(i+j)){
                            star++;
                        }
                    }
                }
            }
        }
        printf("%d\n", star);
        x--;
    }
}