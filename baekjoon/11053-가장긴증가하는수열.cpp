#include <stdio.h>
#include <algorithm>


int main() {

	int n;
	int sets[1002];
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &sets[i]);
	}
	if (n < 2) {
		printf("%d", n);
		return 0;
	}

	int inc[1002];

	inc[0] = 1;
	int max = 1;

	for (int i = 1; i < n; i++) {
		inc[i] = 0;
		for (int j = 0; j < i; j++) {
			if (inc[j] > inc[i] && sets[j] < sets[i]) {
				inc[i] = inc[j];
			}
		}
		inc[i]++;
		if (inc[i] > max) max = inc[i];
	}
	printf("%d", max);

}