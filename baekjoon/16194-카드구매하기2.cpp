#include <stdio.h>

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int main() {


	int n;
	scanf("%d", &n);

	int p[1002];

	int m[1002];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		m[i] = p[i];
	}


	for (int i = 2; i <= n; i++) {
		for (int j = i-1; j >= (i+1)/2; j--) {
			
			m[i] = min(m[i], m[j] + m[i-j]);
		}

	}
	
	printf("%d", m[n]);
}