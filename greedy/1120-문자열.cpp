#include <stdio.h>
#include <string.h>

int main() {

	char a[51];
	char b[51];

	scanf("%s %s", &a, &b);

	int lena = strlen(a);
	int lenb = strlen(b);

	int min = 51;


	for (int i = 0; i <= lenb - lena; i++) {
		int diff = 0;
		for (int j = 0; j < lena; j++) {
			if (a[j] != b[i + j]) {
				diff++;
			}
		}
		if (diff < min) {
			min = diff;
		}
	}
	printf("%d", min);
}