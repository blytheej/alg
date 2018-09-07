#include <stdio.h>

int main() {

	int n, m;
	int a[300002], b[300002];
	int useda[300002] = { 0, };
	int usedb[300002] = { 0, };
	long long int suma = 0;
	long long int sumb = 0;


	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		suma += a[i];
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		sumb += b[i];
	}
	if (suma != sumb) {
		printf("-1");
		return 0;
	}

	int ax = 0;
	int bx = 0;
	int same = 0;
	long long int sum = suma;
	suma = 0;
	sumb = 0;

	while ( ax<n && bx < m) {
		if (useda[ax] == 0) {
			suma += a[ax];
			useda[ax] =  1;
		}
		if (usedb[bx] == 0) {
			sumb += b[bx];
			usedb[bx] = 1;
		}
		if (suma == sumb) {
			same++;
			ax++; bx++;
			suma = 0; sumb = 0;
		}
		else if (suma > sumb) {
			bx++;
		}
		else {
			ax++;
		}
		
	}

	printf("%d", same);
	return 0;
}