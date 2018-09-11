#include <stdio.h>
#include <algorithm>

int main() {

	int tri[503][503];

	int n;
	scanf("%d", &n);

	int num;
	int max;
	scanf("%d", &tri[0][0]);
	int maxsum = tri[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {		
			scanf("%d", &num);

			if (j == 0) {
				tri[i][0] = tri[i - 1][0] + num;
			}
			else if (j == i) {
				tri[i][i] = tri[i - 1][i - 1] + num;
			}
			else {
				max = std::max(tri[i-1][j-1], tri[i-1][j]);
				tri[i][j] = max + num;
			}
			
			if (i == n - 1 && tri[i][j] > maxsum) {
				maxsum = tri[i][j];
			}
		}
	}

	printf("%d", maxsum);
}