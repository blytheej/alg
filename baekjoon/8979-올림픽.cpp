#include <stdio.h>

int main() {
	int n = 0;
	int k = 0;
	int t, gold[1001], silver[1001], bronze[1001] ;

	scanf("%d %d", &n, &k);
	k--;

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		t--;
		scanf("%d %d %d", &gold[t], &silver[t], &bronze[t]);
	}

	int better = 0;
	int g = gold[k];
	int s = silver[k];
	int b = bronze[k];

	for (int i = 0; i < n; i++) {
		if (gold[i] > g) {
			better++;
		}
		else if (gold[i] == g && silver[i] > s) {
			better++;
		}
		else if (gold[i] == g && silver[i] == s && bronze[i] > b) {
			better++;
		}

		printf("%d %d %d %d %d %d %d\n", gold[i], silver[i], bronze[i], g, s, b, better);
	}

	printf("%d", better+1);
}