#include <stdio.h>
#include <stdlib.h>


int comp(const void *a, const void *b) {

	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2) return 1;
	if (num1 > num2) return -1;
	else return 0;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	int ropes[100002];
	for (int i = 0; i < n; i++) {
		scanf("%d", &ropes[i]);
	}

	qsort(ropes,n, sizeof(int), comp);
	

	int max = 0;

	for (int i = 0; i < n; i++) {
		if ((i + 1) * ropes[i] > max) {
			max = (i+1) * ropes[i];
			
		}
	}
	printf("%d",max);
}