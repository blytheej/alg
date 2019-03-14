#include <stdio.h>
#include <math.h>

int n, m, k;
int dep;
long long int sum[2100000] = { 0, };
int data;

void update(int id, int x) {
	int dif = x - sum[id];
	while (id > 0) {
		sum[id] += dif;
		id /= 2;
	}
	return;
}

long long int get_sum(int a, int b) {

	long long int tot = 0;

	int l = a + data;
	int r = b + data;

	while (l <= r) {
		if (l % 2 == 1) {
			tot += sum[l];
			l++;
		}
		if (r % 2 == 0) {
			tot += sum[r];
			r--;
		}
		l /= 2; r /= 2;
	}


	return tot;
}

int main() {

	
	scanf("%d %d %d", &n, &m, &k);
	if (n == 1) {
		dep = 1;
	}
	else {
		dep= (int)log2(n-1) + 1;
	}
	data = pow(2, dep) - 1;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[data + i]);
	}

	for (int i = data; i > 0; i--) {
		sum[i] = sum[2 * i] + sum[2 * i + 1];
	}
	int a, b, c;
	for (int i = 0; i < m+k; i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) update(b+data, c);
		else  printf("%lld\n",get_sum(b, c));
	}
}