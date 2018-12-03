#include <stdio.h>

int main() {

	char c;
	int alpha[26] = { 0, };
	int max = 0;
	char maxa = '?';

	while (scanf("%c", &c) != EOF) {
		if (c >= 'a' && c <= 'z') {
			alpha[c - 97] ++;
		}
		else {
			alpha[c - 65]++;
		}

	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max) {
			max = alpha[i];
			maxa = 'A' + i;
		}
		else if (alpha[i] == max) {
			maxa = '?';
		}
	}

		printf("%c", maxa);


}