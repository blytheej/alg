#include <stdio.h>

int main() {

	long long int n, k;

	scanf("%lld %lld", &n, &k);

	long long int height = (k + n - 1) / n;
	printf("%lld", height);

}