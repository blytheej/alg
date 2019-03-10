#include<stdio.h>
#include <math.h>

int main() {

	long long int x, y,z ;
	while (scanf("%lld %lld", &x, &y) != EOF) {

		z = (100 * y / x);

		if (z >= 99) {
			printf("-1\n");
			continue;
		}

		z++;

		double min = (double)(z * x - 100 * y) / (100 - z);
		printf("%lld\n", (long long int)ceil(min));
	}

}

