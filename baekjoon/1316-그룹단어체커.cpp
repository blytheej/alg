#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int group = 0;

	for (int i = 0; i < n; i++) {

		int a[26] = { 0, };
		char word[102];
		scanf("%s", &word);
		char now = '0';
		bool t = true;
		int k = 0;
		while (word[k] != NULL) {
			if ( (a[word[k] - 97] ) == 1) {
				t = false;
				break;
			}
			now = word[k];

			while (word[k + 1] == now) {
				k++;
			}
			a[now - 97] = 1;
			k++;
		}
		if (t) group++;
	}
	printf("%d", group);

}