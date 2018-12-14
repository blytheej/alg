#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {

	char s1[1002];
	char s2[1002];

	scanf("%s %s", &s1, &s2);

	int sl1, sl2;
	sl1 = strlen(s1);
	sl2 = strlen(s2);

	int m = 0;

	int lcs[1002][1002] = { 0, };

	for (int i = 1; i <= sl1; i++) {
		for (int j = 1; j <= sl2; j++) {

			if (s1[i - 1] == s2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}

			if (m < lcs[i][j]) {
				m = lcs[i][j];
			}

		}
	}

	printf("%d\n", m);

	char str[1002];
	int find = m;

	for (int i = sl1; i > 0; i--) {
		for (int j = sl2; j > 0; j--) {

			if (s1[i - 1] == s2[j - 1] && lcs[i][j] == find) {
				str[find] = s1[i - 1];
				find--;
				if( j>1) i--;
			}

		}
	}

	for (int i = 1; i <= m; i++) {
		printf("%c", str[i]);
	}
}