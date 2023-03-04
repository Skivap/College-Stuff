#include <string.h>
#include <stdlib.h>

typedef struct {
	int grade; 
	char* name;
} Student;

//create a student list size n
Student* Create_(int n){
	Student *a = malloc(n*sizeof(Student));
	return a;
}
//set value of the student's grade and name
void SetVal_(Student* a, int i, int point, char arr[]){
	a[i].grade = point;
	a[i].name = malloc(51 * sizeof(char));
	strcpy(a[i].name, arr);
}
//compare the grades of the student, return 1 if id2 has higher priority than id1
int Compare_(Student* a, int id1, int id2){
	if(a[id1].grade < a[id2].grade) return 1;
	else if(a[id1].grade > a[id2].grade) return 0;
	else return strcmp(a[id2].name, a[id1].name);
}
//swap student 
void Swap_(Student* a, int id1, int id2){
	char *temp;
	temp = a[id1].name;
	a[id1].name = a[id2].name;
	a[id2].name = temp;
	
	int num;
	num = a[id1].grade;
	a[id1].grade = a[id2].grade;
	a[id2].grade = num;
}
//free the student list 
void Free_(Student* a, int n){
	for(int i=0;i<n;i++){
		free(a[i].name);
	}
	free(a);
}



