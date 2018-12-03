#include <stdio.h>
#include <algorithm>


int main() {

	int tc;
	
	
	scanf("%d", &tc);

	while (tc--) {

		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);

		if (y == n) {
			y = 0;
		}
		int k = x;
		int result = -1;

		for (k; k < m * n; k += m) {
			if (k % n == y) {
				result = k;
				break;
			}
		}

		printf("%d\n", result);
	}
	


}