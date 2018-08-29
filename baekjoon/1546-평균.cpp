#include <stdio.h>
#include <math.h>

int main() {

	float score[1001];
	int n = 0;
	scanf("%d", &n);
	float sum = 0;
	float high = 0;

	for (int i = 0; i < n; i++) {
		scanf("%f", &score[i]);
		if (score[i] > high) {
			high = score[i];
		}
	}
	for (int i = 0; i < n; i++) {
		score[i] = score[i] / high * 100;
		sum += score[i];
	}
	sum = sum / n;
	printf("%.2f", sum);

}