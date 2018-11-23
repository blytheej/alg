#include <stdio.h>

int main() {

	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int n;
		scanf("%d", &n);

		int sum = 0;
		int score[1002];
		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			sum += score[i];
		}

		int up = 0;

		for (int i = 0; i < n; i++) {
			if (score[i] * n > sum) {
				up++;
			}
		}

		printf("%.3f%%\n", (float)up / n * 100);
	}
}