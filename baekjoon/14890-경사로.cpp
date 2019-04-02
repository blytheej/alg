#include <stdio.h>

int main() {

	int n, l;
	scanf("%d %d", &n, &l);

	int m[102][102];
	int t[102][102];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &m[i][j]);
			t[j][i] = m[i][j];
		}
	}

	int ways = 0;
	bool st1[102][102] = { false, };
	for (int i = 1; i <= n; i++) {
		int j = 1;
		int st = 0; // stair
		int fl = 0;
		while (true) {
			if (j == n) {
				ways++; break;
			}
			if (m[i][j] == m[i][j + 1]) {
				//pass;
				j++;
			}
			else if (m[i][j] == m[i][j + 1] + 1) {
				//going down
				st = 0;
				fl = m[i][j + 1];
				for (int k = 1; k <= l && j+k <= n; k++) {
					if (fl == m[i][j + k]) {
						st1[i][j + k] = true;
						st++;
					}
				}
				if (st == l) {
					j += l ;
				}
				else {
					break;
				}
			}

			else if (m[i][j] + 1 == m[i][j + 1]) {

				st = 0;
				for (int k = 0; k < l && j-k >0; k++) {
					if (!st1[i][j-k] && m[i][j - k] == m[i][j]) {
						st1[i][j - k] = true;
						st++;
					}
				}
				if (st == l) {
					j++;
				}
				else {
					break;
				}

			}
			else {
				break;
			}

		}
	}

	bool st2[102][102] = { false, };
	for (int i = 1; i <= n; i++) {
		int j = 1;
		int st = 0; // stair
		int fl;
		while (true) {
			if (j == n) {
				ways++; break;
			}
			if (t[i][j] == t[i][j + 1]) {
				//pass;
				j++;
			}
			else if (t[i][j] == t[i][j + 1] + 1) {
				//going down
				st = 0;
				fl = t[i][j + 1];
				for (int k = 1; k <= l && j + k <= n; k++) {
					if (fl == t[i][j + k]) {
						st2[i][j + k] = true;
						st++;
					}
				}
				if (st == l) {
					j += l;
				}
				else {
					break;
				}
			}

			else if (t[i][j] + 1 == t[i][j + 1]) {

				st = 0;
				for (int k = 0; k < l && j - k >0; k++) {
					if (!st2[i][j - k] && t[i][j - k] == t[i][j]) {
						st2[i][j - k] = true;
						st++;
					}
				}
				if (st == l) {
					j++;
				}
				else {
					break;
				}

			}
			else {
				break;
			}

		}
	}

	printf("%d", ways);
}
