#include <stdio.h>

int main() {

	char c[1000001];
	int words = 0;

	while (scanf("%s", &c) != EOF) {
		words++;
	}

	printf("%d", words);
}