#include <stdio.h>

int max(int x, int y) {
	if (x > y) return x;
	else return y;
}

int max(int x, int y, int z) {
	if (x >= y && x >= z) return x;
	else if (y >= x && y >= z) return y;
	else return z;
}


int main() {

	int n = 0;
	scanf("%d", &n);

	int wine[10002];
	int drink[10002][3];

	for (int i = 0; i < n; i++) {
		scanf("%d", &wine[i]);
	}
	drink[0][0] = wine[0];
	drink[0][1] = 0;
	drink[0][2] = 0;

	if (n == 1) {
		printf("%d", wine[0]);
		return 0;
	}
	int drinkmax = 0; 

	drink[1][0] = wine[0] + wine[1];
	drink[1][1] = wine[1];
	drink[1][2] = 0;
	
	int a = max(drink[1][0], drink[1][1], drink[1][2]);

	if (drinkmax < a) drinkmax = a;

	drink[2][0] = wine[1] + wine[2];
	drink[2][1] = wine[0] + wine[2];
	drink[2][2] = wine[2];
	a = max(drink[2][0], drink[2][1], drink[2][2]);

	if (drinkmax < a) drinkmax = a;

	for (int i = 3; i < n; i++) {
		
			drink[i][0] =  max(drink[i-1][1], drink[i-1][2]) + wine[i];
			drink[i][1] = max(drink[i - 2][0], drink[i - 2][1], drink[i - 2][2]) + wine[i];
			drink[i][2] = max(drink[i - 3][0], drink[i - 3][1], drink[i - 3][2]) + wine[i];
		
		a = max(drink[i][0], drink[i][1], drink[i][2]);

		if (drinkmax < a) drinkmax = a;
	}
	

	printf("%d", drinkmax);

}