#include <stdio.h>

int main() {

	int coins[11];
	int n = 0;
	int sum = 0;
	int howmany = 0;

	scanf("%d %d", &n, &sum);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coins[i]);
	}

	for (int i = n - 1; i >= 0; i -- ) {
		if (sum == 0) {
			break;
		}
		int coin = sum / coins[i];
		if (coin > 0) {
			howmany += coin;
			sum -= coin * coins[i];
		}
	}

	printf("%d", howmany);
}