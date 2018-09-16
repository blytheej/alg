#include <stdio.h>


long long int getGCD(long long int x, long long int y) {
	long long int a, b;
	if (x > y) { a = x; b = y; }
	else { b = x; a = y; }
	long long int small;
	while (b) {
		small = a % b;
		a = b;
		b = small;
	}
	return a;
}


int main() {

	long long int a, b, x, y;
	scanf("%lld %lld %lld %lld", &a, &b, &x, &y);

	long long int sets = 0;

	long long int ra, rb, gcd;
	gcd = getGCD(x, y);
	ra = x / gcd;
	rb = y / gcd;

	long long int maxw = a / ra;
	long long int maxh = b / rb;

	if (maxw > maxh) {
		printf("%lld", maxh);
	}
	else {
		printf("%lld", maxw);
	}

}