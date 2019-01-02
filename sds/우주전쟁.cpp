#include <stdio.h>

int tc;
int dmg[20002];

void clear() {
	for (int i = 0; i < 20002; i++) {
		dmg[i] = 0;
	}
}

int main() {

	scanf("%d", &tc);

	for (int test = 1; test <= tc; test++) {


	int n, m, b;
	scanf("%d %d %d", &n, &m, &b);

	int dmgs, s;

	clear();

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &dmgs, &s);
		dmg[dmgs] = s;
	}

	long long int sum = 0;
	int left = n;
	int def = b;

	while (left > 0 && def <= 20000) {
		while (dmg[def] > 0 && left > 0) {
			sum += def;
			dmg[def]--;
			left--;
		}
	
		if (def < 20000) {
			int h = def / 2;

			for (int i = 1; i <= h; i++) {
				if (i == def - i) {
					while (dmg[i] >= 2 && left > 0) {
						sum += def;
						left--;
						dmg[i] -= 2;
					}
				}
				else {
					while (dmg[i] > 0 && dmg[def - i] > 0 && left > 0) {
						sum += def;
						left--;
						dmg[i]--;
						dmg[def - i]--;
					}

				}
			}
		}
		def++;
	}


	printf("#%d ", test);
	if (left == 0) {
		printf("%lld\n", sum);
	}
	else {
		printf("-1\n");
	}

	}

}
