
#include <stdio.h>

int broke[10] = { 0, };

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int check(int a) {
	int t = 0;
	if (a == 0 && !broke[0]) {
		t = 1;
	}
	while (a > 0) {
		t++;
		if (broke[a % 10]) {
			return 0;
		}
		a /= 10;
	}

	return t;
}

int main() {


	int n, m;
	scanf("%d %d", &n, &m);

	int k;
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		broke[k] = 1;
	}
	int move = check(n);
	if (move == 0) {
		move = 500000;
	}
	int inc = n, dec = n;

	int cnt = 0;
	
	while (true) {
		if ( check(inc) || check(dec) || dec == 100 || inc == 100) {
			int channel = 0;
			int ci = check(inc);
			int cd = check(dec);
			if (ci && cd) {
				channel = min(ci, cd);
			}
			else if (ci) {
				channel = ci;
			}
			if (cd) {
				channel = cd;
			}
			move = min(move, channel + cnt);
			break;
		}
		cnt++;
		inc++;
		dec--;
	}
	
	move = min(move, max(n,100) - min(n,100));
	printf("%d", move);
}