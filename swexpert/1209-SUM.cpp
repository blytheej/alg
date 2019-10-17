#include <stdio.h>

int main() {

	for (int tc = 1; tc <= 10; tc++) {

		int test;
		scanf("%d", &test);
		int num[102][102];

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%d", &num[i][j]);
			}
		}

		int maxsum = 0;

		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += num[i][j];
			}
			if (sum > maxsum) {
				maxsum = sum;
			}
		}

		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += num[j][i];
			}
			if (sum > maxsum) {
				maxsum = sum;
			}
		}

		int sum = 0;
		for (int i = 0; i < 100; i++) {
			sum += num[i][i];
		}
		if (sum > maxsum) {
			maxsum = sum;
		}

		sum = 0;
		for (int i = 0; i < 100; i++) {
			sum += num[i][99-i];
		}
		if (sum > maxsum) {
			maxsum = sum;
		}

		printf("#%d %d\n", test, maxsum);

	}
	

}