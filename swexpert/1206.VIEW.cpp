#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int getmax(int a, int b, int c, int d) {

	int maxint = a;
	
	maxint = max(maxint, b);
	maxint = max(maxint, c);
	maxint = max(maxint, d);

	return maxint;

}

int main() {


	for (int tc = 1; tc <= 10; tc++) {

		int w;
		int h[1003];

		int views = 0;

		scanf("%d", &w);
		for (int i = 0; i < w; i++) {
			scanf("%d", &h[i]);
		}

		for (int i = 2; i < w - 2; i++) {
			int maxh = getmax(h[i - 2], h[i - 1], h[i + 1], h[i + 2]);
			//if ith building has view
			if (h[i] > maxh) {
				views += h[i] - maxh;
			}
		}

		printf("#%d %d\n", tc, views);
	}


}