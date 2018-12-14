#include <stdio.h>


int main() {

	int d;
	int num[10] = { 0, };
	int big = 0;

	while (scanf("%1d", &d) != EOF) {
		if (d == 9) {
			num[6]++;
		}
		else {
			num[d]++;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i==6) {
			if ((num[i] + 1) / 2 > big) {
				big = (num[i] + 1) / 2;
			}
		}
		else if (num[i] > big) {
			big = num[i];
		}
	}

	printf("%d", big);
}