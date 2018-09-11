#include <stdio.h>
#include <algorithm>

int main() {

	int n, k;
	int over = 0;
	scanf("%d %d", &n, &k);

	int coins[102];
	int ways[10002] = { 0, };

	int coin;
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin);
		if (coin > 10000) {
			over++;
		}
		else {
			coins[i - over] = coin;
		}
	}
	n -= over;
	std::sort(coins, coins + n);

	ways[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int sum = coins[i]; sum <= k; sum++) {
			ways[sum] += ways[sum - coins[i]]; 
		}
		
	}
	printf("%d", ways[k]);
}