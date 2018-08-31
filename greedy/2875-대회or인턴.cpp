#include <stdio.h>

int main() {

	int g, b, intern;
	
	scanf("%d %d %d", &g, &b, &intern);

	int max = b;
	if (g / 2 < b) max = g / 2;

	int left = g + b - 3 * max;

	if (left >= intern) { printf("%d", max); return 0; }

	intern -= left;

	int breakt = 0;
	breakt = (intern + 2) / 3;
	max -= breakt;
	printf("%d", max);
}	