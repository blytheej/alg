#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int cnt[102][10];

	if (n == 1) {
		printf("9");
		return 0;
	}

	cnt[0][0] = 0;
	for (int i = 1; i < 10; i++) {
		cnt[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		cnt[i][0] = cnt[i - 1][1] % 1000000000;
		cnt[i][9] = cnt[i - 1][8] % 1000000000;

		for (int j = 1; j < 9; j++) {
			cnt[i][j] = (cnt[i - 1][j - 1] + cnt[i - 1][j + 1]) % 1000000000;
		}
	}

	int sum = 0;

	for (int i = 0; i < 10; i++) {
		sum = (sum + cnt[n - 1][i]) % 1000000000;
	}

	printf("%d", sum % 1000000000);
}