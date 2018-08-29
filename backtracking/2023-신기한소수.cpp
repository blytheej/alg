#include <stdio.h>

int n = 0;

int checkprime(int x) {
	
	bool prime = true;
	if (x == 2) return true;
	for (int i = 2; i < x; i++) {
		if (x%i == 0) {
			prime = false;
			break;
		}
	}
	return prime;

}

int makeprime(int x, int len) { // now num, num length

	if (len == n) {
		printf("%d\n", x);
	}

	for (int i = 0; i < 10; i++) {
		int a = x * 10 + i;
		if (checkprime(a)) {
			makeprime(a, len + 1);
		}
	}


	return 0;
}


int main() {

	scanf("%d", &n);

	makeprime(2, 1);
	makeprime(3, 1);
	makeprime(5, 1);
	makeprime(7, 1);
	


}