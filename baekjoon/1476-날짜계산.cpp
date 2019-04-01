#include <stdio.h>

int main() {


	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int year;
	int l = a;
	if (a == 15) { a = 0; }
	if (b == 28) { b = 0; }
	if (c == 19) { c = 0; }

	for (int i = l; i <= 7980; i += 15) {
		if (i % 28 == b && i % 19 == c) {
			year = i;
			break;
		}
	}

	printf("%d", year);

} 