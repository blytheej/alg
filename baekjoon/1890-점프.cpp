#include <stdio.h>


int n;
int map[102][102];
long long int way[102][102] = { 0, };

int main() {
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	if (map[0][0] == 0) {
		printf("0");
		return 0;
	}
	way[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (i == n - 1 && j == n - 1) {
				break;
			}
			int go = map[i][j];

			if (i + go < n) {
				way[i + go][j] += way[i][j];
			}
			if (j + go < n) {
				way[i][j + go] += way[i][j];
			}
		}
	}
	printf("%lld", way[n-1][n-1]);
}