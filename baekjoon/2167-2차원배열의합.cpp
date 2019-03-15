#include <stdio.h>


int main() {


	int n, m;
	scanf("%d %d", &n, &m);

	int arr[302][302];
	int sumr[302][302] = { 0, };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sumr[i][j] = sumr[i - 1][j] + sumr[i][j - 1] - sumr[i - 1][j - 1] + arr[i][j];
		}
	}



	int test;
	scanf("%d", &test);
	int x1, x2, y1, y2;

	for (int t = 0; t < test; t++) {
		
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		printf("%d\n", sumr[x2][y2] - sumr[x2][y1-1] - sumr[x1-1][y2] + sumr[x1-1][y1-1]);
	

	}



}