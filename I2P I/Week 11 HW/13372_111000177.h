void Swap(int*, int*);

void Replace(int*, int*);

void Switch(int**, int**);


void Swap(int* a, int* b){
    char temp1, temp2;
    int num1, num2, temp;
    scanf(" %c %c %d %d", &temp1, &temp2, &num1, &num2);
    if(temp1=='A' && temp2 == 'B'){
        temp = a[num1];
        a[num1] = b[num2];
        b[num2] = temp;
    }else if(temp1=='B' && temp2 == 'A'){
        temp = b[num1];
        b[num1] = a[num2];
        a[num2] = temp;
    }else if(temp1 == temp2 && temp1 =='A'){
        temp = a[num1];
        a[num1] = a[num2];
        a[num2] = temp;
    }else{
        temp = b[num1];
        b[num1] = b[num2];
        b[num2] = temp;
    }
}
void Replace(int* a, int* b){
    char temp1;
    int num1, temp;
    scanf(" %c %d %d", &temp1, &num1, &temp);
    if(temp1=='A') a[num1] = temp;
    else b[num1] = temp;
}
void Switch(int** a, int** b){
    int *temp = *a;
    *a = *b;
    *b = temp;
}