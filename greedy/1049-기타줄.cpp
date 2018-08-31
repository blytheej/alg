#include <stdio.h>

int main() {

	int n, m;

	int cheap_p = 1001;
	int cheap_o = 1001;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < cheap_p) {
			cheap_p = a;}
		if (b < cheap_o) {
			cheap_o = b;}
	}
	// one * 6 is cheaper than package
	if (cheap_p > cheap_o * 6 ) {
		printf("%d\n", n *cheap_o);
		return 0;
	}

	int packages = n / 6;
	int left = n % 6;
	//one * left > package
	if (left * cheap_o > cheap_p) {
		packages++;
		left = 0;
	}
	int total = packages * cheap_p + left * cheap_o;
	printf("%d", total);
}