#include <stdio.h>


int main() {

	int n;
	int tall[11];
	int wh[11] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tall[i]);
	}

	for (int i = 0; i < n; i++) {
		int h = tall[i];
		int blank = 0;
		int now = 0;
		while (true) {
			if (blank == h && wh[now] == 0) {
				wh[now] = i + 1;
				break;
			}
			if (wh[now] == 0) {
				blank++;
			}
			now++;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", wh[i]);
	}
}