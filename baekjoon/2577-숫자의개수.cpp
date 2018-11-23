#include <stdio.h>


int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int n = a * b * c;

	int num[10] = { 0, };

	while (n >= 10) {
		num[n % 10]++;
		n /= 10;
	}

	num[n]++;

	for (int i = 0; i < 10; i++) {
		printf("%d\n", num[i]);
	}
}