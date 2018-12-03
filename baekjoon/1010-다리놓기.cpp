#include <stdio.h>

int main() {

	int tc;
	scanf("%d", &tc);
	int n, m;
	while (tc--) {
		scanf("%d %d", &n, &m);


		long long int pick[31];

		pick[0] = 1;

		for (int i = 1; i <= n; i++) {
			pick[i] = pick[i-1] * (m + 1 - i) / i;
		}

		printf("%lld\n", pick[n]);

	}
}