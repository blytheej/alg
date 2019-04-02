#include <stdio.h>


bool one(int a) {

	if (a < 100) {
		return true;
	}
	else {
		int n1, n2, n3;
		n1 = a % 10;  a /= 10;
		n2 = a % 10; a /= 10;
		n3 = a;
		if (n3 - n2 == n2 - n1) {
			return true;
		}
		else {
			return false;
		}
	}

}

int main() {

	int n;
	scanf("%d", &n);
	int num = 0;

	for (int i = 1; i <= n; i++) {
		if (one(i)) {
			num++;
		}
	}

	printf("%d", num);


}