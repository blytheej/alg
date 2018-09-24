#include <stdio.h>


int n;
int zero = 0;
int one = 0;
int minus = 0;
int paper[2200][2200];

void check(int x, int y, int len) {
	
	int num = paper[x][y];
	bool same = true;
	
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (paper[i][j] != num) {
				same = false;
				break;
			}
		}
	}
	if (same) {
		if (num == 2) {
			minus += 1;
		}
		else if (num == 0) {
			zero += 1;

		}
		else {
			one += 1;
		}
		return;
	}
	else {
		int nlen = len / 3;
		for (int i = x; i < x + len; i += nlen) {
			for (int j = y; j < y + len; j += nlen) {
				check(i, j, nlen);
			}
		}
	}
	

}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &paper[i][j]);
			if (paper[i][j] == -1) paper[i][j] += 3;
		}
	}

	check(0, 0, n);

	printf("%d\n%d\n%d\n", minus, zero, one);
}