#include <stdio.h>

int main() {

	int give = 0;
	scanf("%d", &give);
	give = 1000 - give;
	int coins[6] = { 500, 100, 50, 10, 5, 1};

	int take = 0;

	for (int i = 0; i < 6; i++) {
		int coin = give / coins[i];
		if (coin > 0) {
			take += coin;
			give -= coin * coins[i];
		}
	}
	printf("%d", take);

}