#include <stdio.h>



int main() {
	int tc = 0;
	int n = 0;
	scanf("%d", &tc);

	int plus[13];
	plus[1] = 1;
	plus[2] = 2;
	plus[3] = 4;
		 
	for (int i = 4; i <= 11; i++) {
		plus[i] = plus[i - 1] + plus[i - 2] + plus[i - 3];
	}

	for (int i = 0; i < tc; i++) {
		scanf("%d", &n);
		printf("%d\n", plus[n]);
	}

}