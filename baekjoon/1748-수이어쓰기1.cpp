#include <stdio.h>


int main() {


	int n;
	int k = 1;
	scanf("%d", &n);

	int cnt = 0;
	int num = 1;
	while (true) {
		if (n - 10 * k >= 0) {
			cnt += 9 * num * k;
			k *= 10;
			num++;
			
		}
		else {
			cnt += (n - k + 1) * num;
			break;
		}
	}
	printf("%d", cnt);
}