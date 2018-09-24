#include <stdio.h>

int mata[101][101];
int matb[101][101];
int n, m, k;

int matrix(int a, int b) {

	int sum = 0;

	for (int i = 0; i < m; i++) {
		sum += mata[a][i] * matb[i][b];

	}

	return sum;

}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mata[i][j]);
		}
	}
	scanf("%d %d", &m, &k);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &matb[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", matrix(i, j));
		}
		printf("\n");
	}


}