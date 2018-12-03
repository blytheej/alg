#include <stdio.h>

int main() {


	int tc;
	scanf("%d", &tc);
	
	while (tc--) {
		int w, h, n;

		scanf("%d %d %d", &w, &h, &n);

		int s = n % w;
		int r = n / w + 1;

		if (s == 0) { s = w; r = n / w; }
		if (r < 10) {
			printf("%d0%d\n", s, r);
		}
		else {
			printf("%d%d\n", s, r);
		}

	}


}