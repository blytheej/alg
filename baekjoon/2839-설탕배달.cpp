#include <stdio.h>



int main() {

	int n;
	scanf("%d", &n);

	int sum = 0;

	int k = n / 5;
	int left = n % 5;

	for (left; left <= n; left +=5) {
		if (left == 0) {
			sum = n / 5;
			break;
		}
		if (left % 3 == 0) {
			sum = left / 3 + (n - left) / 5;
			break;
		}

	}

	if (sum == 0) {
		printf("-1");
	}
	else {
		printf("%d", sum);
	}

}