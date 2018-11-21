#include <stdio.h>

int main() {

	int n = 0;

	char a = 0;

	while (scanf("%c", &a) != EOF) {

		if (n != 0 && n % 10 == 0) {
			printf("\n");
		}

		n++;
		printf("%c", a);

	}

}