#include <stdio.h>

int main() {

	int zero[43];
	int one[43];


	zero[0] = 1;
	zero[1] = 0;
	one[0] = 0;
	one[1] = 1;

	for (int i = 2; i < 41; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int num;
		scanf("%d", &num);
		printf("%d %d\n", zero[num], one[num]);
	}


}