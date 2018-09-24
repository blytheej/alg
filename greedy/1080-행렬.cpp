#include <stdio.h>

int n, m;
int A[51][51];
int B[51][51];
int cnt = 0;


bool cmp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void turn(int x, int y) {

	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (A[i][j] == 0) {
				A[i][j] = 1;
			}
			else {
				A[i][j] = 0;
			}
		}
	}

}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &A[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &B[i][j]);
		}
	}

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (A[i][j] != B[i][j]) {
				cnt++;
				turn(i, j);
			}
		}
	}

	if (cmp()) {
		printf("%d", cnt);
	}
	else {
		printf("-1");
	}
	


}