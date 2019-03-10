#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int arr[10002] = { 0, };

	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d",&a);
		arr[a]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] > 0) {
			for (int j = 0; j < arr[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
}