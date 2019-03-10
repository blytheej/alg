#include <stdio.h>


int main() {

	int tc;
	scanf("%d", &tc);

	long long int p[70];

	p[0] = 1;
	p[1] = 1;
	p[2] = 2;
	p[3] = 4;

	for (int i = 4; i <= 67; i++) {
		p[i] = p[i - 1] + p[i - 2] + p[i - 3] + p[i - 4];
	}

	int num;

	for (int i = 0; i < tc; i++) {
		scanf("%d", &num);
		printf("%lld\n", p[num]);
	}

}