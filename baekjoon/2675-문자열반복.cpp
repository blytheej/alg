#include <stdio.h>

int main() {

	int tc; 
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {

		int n;
		char word[21];

		scanf("%d %s", &n, &word);

		int i = 0;
		while (word[i] != NULL) {

			for (int j = 0; j < n; j++) {
				printf("%c", word[i]);
			}
			i++;

		}
		printf("\n");
	}
}