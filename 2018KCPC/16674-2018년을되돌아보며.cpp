#include<stdio.h>

int main() {

	int num[4] = { 0, };

	int n;

	while (scanf("%1d", &n) != EOF) {

		if (n == 2) {
			num[0]++;
		}
		else if (n == 0) {
			num[1]++;
		}
		else if (n == 1) {
			num[2]++;
		}
		else if (n == 8) {
			num[3]++;
		}
		else {
			printf("0");
			return 0;
		}
	}

	if (num[0] == num[1] && num[1] == num[2] && num[2] == num[3]) {
		printf("8");
	}
	else if (num[0] * num[1] * num[2] * num[3] > 0) {
		printf("2");
	}
	else {
		printf("1");
	}


}