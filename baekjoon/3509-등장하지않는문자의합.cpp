#include <stdio.h>

int main() {
	
	int tc = 0;
	scanf("%d", &tc);


	while (tc--) {

		char data[1001];
		char alpha[26] = { 0, };
		char a;
		scanf("%s", &data);
		for (int i = 0; i < 1000; i++) {
			data[i] = (int)data[i];
			if (data[i] > 64 && data[i] < 91) {
				alpha[data[i] - 65] = 1;
			}
			else break;
		}
		int sum = 0;

		for (int i = 0; i < 26; i++) {
			if (alpha[i] == 0) {
				sum += i + 65;
			}
		}
		printf("%d\n", sum);
	}
}