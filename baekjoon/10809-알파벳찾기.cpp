#include <stdio.h>

int main() {

	char word[102];
	int wh[26];

	for (int i = 0; i < 26; i++) {
		wh[i] = -1;
	}

	scanf("%s", &word);

	int i = 0;


	while (word[i] >= 'a'){
		if (wh[word[i] - 97] < 0) {
			wh[word[i] - 97] = i;
		}
		i++;
	}

	for (int k = 0; k < 26; k++) {
			printf("%d ", wh[k]);
	}
}