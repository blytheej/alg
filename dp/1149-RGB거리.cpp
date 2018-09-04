#include <stdio.h>


int min(int x, int y) {
	if (x < y) return x;
	else return y;
}

int min(int x, int y, int z) {
	if (x <= y && x <= z) return x;
	if (y <= x && y <= z) return y;
	else return z;
}


int main() {

	int n = 0;
	scanf("%d", &n);
	if (n == 0) {
		printf("0");
		return 0;
	}

	int paint[1002][4];
	int r[1002];
	int g[1002];
	int b[1002];

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &r[i], &g[i], &b[i]);
	}
	paint[0][0] = r[0];
	paint[0][1] = g[0];
	paint[0][2] = b[0];

	for (int i = 1; i < n; i++) {
		paint[i][0] = min(paint[i - 1][1], paint[i - 1][2]) + r[i];
		paint[i][1] = min(paint[i - 1][0], paint[i - 1][2]) + g[i];
		paint[i][2] = min(paint[i - 1][0], paint[i - 1][1]) + b[i];
	}
	
	printf("%d", min(paint[n-1][0], paint[n - 1][1], paint[n - 1][2]));


}