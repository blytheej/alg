#include <stdio.h>

int main() {

	int tc;
	scanf("%d", &tc);

	long long int wave[102];
	wave[0] = 1;
	wave[1] = 1;
	wave[2] = 1;
	wave[3] = 2;
	wave[4] = 2;

	for (int i = 5; i <= 100; i++) {
		wave[i] = wave[i - 1] + wave[i - 5];
	}

	for (int i = 0; i < tc; i++) {
		int n;
		scanf("%d", &n);

		printf("%lld\n", wave[n-1]);
	}

}