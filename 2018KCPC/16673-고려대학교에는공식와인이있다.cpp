#include <stdio.h>

int main() {

	int c, k, p;
	scanf("%d %d %d", &c, &k, &p);

	int wine = k * c * (c + 1) / 2 + p * c * (c+1) * (2 * c +1 ) / 6;

	printf("%d", wine);
}