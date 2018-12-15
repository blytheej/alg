#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);


	if (n < 11) {
		printf("1");
	}
	else if (n < 111) {
		printf("2");
	}
	else if (n < 1111) {
		printf("3");
	}
	else if (n < 11111) {
		printf("4");
	}
	else if (n < 111111) {
		printf("5");
	}
	else if (n < 1111111) {
		printf("6");
	}
	else if (n < 11111111) {
		printf("7");
	}
	else if (n < 111111111) {
		printf("8");
	}
	else {
		printf("9");
	}
}