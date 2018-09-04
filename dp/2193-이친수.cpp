#include <stdio.h>

int main() {
	
	int n = 0;
	scanf("%d", &n);

	long long int fri[100][2];
	fri[0][0] = 0;
	fri[0][1] = 0;
	fri[1][0] = 0;
	fri[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		fri[i][0] = fri[i - 1][0] + fri[i - 1][1];
		fri[i][1] = fri[i - 1][0];
	}
	printf("%lld", fri[n][0]+fri[n][1]);
}