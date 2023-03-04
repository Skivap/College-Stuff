    //Domo: When can we go out?
    
    #include <stdio.h>
    int solution = 0;
    int domo = 1;
    int j = 0;
    int pow2[11] = {1,2,4,8,16,32,64,128,256,512,1024};
    char input[30];
    void function(int x){
        if(x<0){
            domo = 0;
            return;
        }
        char ch = input[j];
        j++;
        if(ch=='\0') domo = 0;
        if(ch=='1'){
            solution += pow2[x] * pow2[x];
        }else if(ch=='2'){
            for(int i=0;i<4;i++){
                function(x-1);
            }
        }
    }
    int main(){
        int x;
        scanf("%d", &x);
        scanf("%s", input);
        getchar();
        function(x);
        if(input[j]!='\0'){
            domo = 0;
        }
        if(domo){
            printf("%d", solution);
        }else{
            printf("Domo");
        }
    }