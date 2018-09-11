#include <stdio.h>


int main() {

	int tile[1002];
	int two[1002];
	int n;
	scanf("%d", &n);

	tile[0] = 0;
	two[0] = 0;
	tile[1] = 1;

	tile[2] = 2;

	for (int i = 3; i <= n; i++) {
		tile[i] = tile[i - 1] + tile[i - 2];
		tile[i] %= 10007;

	}

	printf("%d", tile[n]);


}