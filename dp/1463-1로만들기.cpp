#include <stdio.h>


int min(int a, int b, int c) {
	if (a <= b && a <= c) {
		return a;
	}
	else if (b <= a && b <= c) {
		return b;
	}
	else {
		return c;
	}
}


int main() {

	int n = 0;
	scanf("%d", &n);

	int make1[1000002];
	make1[2] = 1;
	make1[3] = 1;

	for (int i = 4; i <= n; i++) {

		int t2 = 1000000;
		int t3 = 1000000;
		int t1 = make1[i-1];

		if(i % 2 == 0){
			t2 = make1[i / 2];
		}
		if (i % 3 == 0) {
			t3 = make1[i / 3];
		}
		int minn = min(t1, t2, t3);
		make1[i] = minn + 1;
	}
	printf("%d", make1[n]);

}