#include <stdio.h>

int main() {

	int n;
	int card[10002];
	int p[10002] = { 0, };

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &card[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int c = 0; c + i <= n; c++) {
			if (p[c + i] < p[c] + card[i]) {
				p[c + i] = p[c] + card[i];
			}
		}
	}
	printf("%d", p[n]);
}