#include <stdio.h>


int max(int x, int y) {
	if (x > y) return x;
	else return y;
}

int main() {

	int n = 0;
	scanf("%d", &n);

	int stairs[302];
	int scores[302][3]; /// max, by 1 step, by 2 step
	
	stairs[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &stairs[i]);
	}
	scores[1][0] = stairs[1];
	scores[1][1] = stairs[1];
	scores[1][2] = 0;
	scores[2][1] = stairs[1] + stairs[2];
	scores[2][2] = stairs[2];
	scores[2][0] = scores[2][1];


	for (int i = 3; i <= n; i++) {
		scores[i][1] = scores[i-1][2] + stairs[i];
		scores[i][2] = scores[i-2][0] + stairs[i];
		scores[i][0] = max(scores[i][1], scores[i][2]);
	}
	printf("%d", scores[n][0]);
}