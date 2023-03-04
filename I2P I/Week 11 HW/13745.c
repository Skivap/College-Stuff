#include <stdio.h>
#include <stdlib.h>
#include "13745_111000177.h"
#include <math.h>

int main() {
	int len;
	int **ans;	
	scanf("%d", &len);
	int *a = (int*)malloc(len * sizeof(int));
	for (int i = 0;i < len;i++) scanf("%d", &a[i]);
	ans = s(a,len);
	print(ans,len);
	free(a);
	return 0;
}