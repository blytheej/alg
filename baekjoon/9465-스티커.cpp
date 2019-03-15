#include <stdio.h>


int max(int a, int b) {
	if (a > b) return a;
	else return b;
}


int main() {


	int tc;
	scanf("%d", &tc);

	
	for (int test = 0; test < tc; test++) {

		int n;
		int sco[2][100020];
		int sum[2][100020];
		sum[0][0] = 0;
		sum[0][1] = 0;
		sum[1][0] = 0;
		sum[1][1] = 0;
		

		scanf("%d", &n);
		for (int i = 2; i < n+2; i++) {
			scanf("%d", &sco[0][i]);
		}
		for (int i = 2; i < n+2; i++) {
			scanf("%d", &sco[1][i]);
		}

		for (int i = 2; i < n + 2; i++) {
			sum[0][i] = max(sum[1][i - 2], sum[1][i - 1]) + sco[0][i];
			sum[1][i] = max(sum[0][i - 2], sum[0][i - 1]) + sco[1][i];
		}

		printf("%d\n", max(sum[0][n+1], sum[1][n+1]));
	}


}