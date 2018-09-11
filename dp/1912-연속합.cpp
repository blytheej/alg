#include <stdio.h>

int main() {

	int sum[1000002];
	int min[1000002] = { 0, };
	int max;

	int n;
	scanf("%d", &n);

	int num;
	int nsum = 0; 
	int nmin = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		nsum += num;
		sum[i] = nsum;
		min[i] = nmin;
		if (sum[i] < nmin) {
			nmin = sum[i];
		}
	}

	max = sum[0];

	for (int i = 0; i < n; i++) {

		if (sum[i] - min[i] > max) {
			max = sum[i] - min[i];
		}
	}

	printf("%d", max);
}