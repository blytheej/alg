#include <stdio.h>
#include <string.h>

int main() {

	
	char s1[4002];
	char s2[4003];
	int l1, l2;
	int eq[4002][4002] = { 0, };

	scanf("%s %s", &s1, &s2);
	l1 = strlen(s1);
	l2 = strlen(s2);


	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++) {
			if (s1[i] == s2[j]) {
				eq[i][j] = 1;
			}
		}
	}


	int max = 0;

	for (int i = 1; i < l1; i++) {
		for (int j = 1; j < l2; j++) {
			if (eq[i][j] > 0) {
				eq[i][j] = eq[i - 1][j - 1] +1;
			}
			if (eq[i][j] > max) { max = eq[i][j]; }
		}
	}
	printf("%d", max);

}