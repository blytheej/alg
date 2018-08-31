#include <stdio.h>

int main() {


	int num[50];
	char pm[50];
	int lenn = 0;
	int lenp = 0;
	char nowc;
	int now;

	
	while (true) {
		//get num
		scanf("%d", &now);
		num[lenn] = now;
		lenn++;
		//get + -
		scanf("%c", &nowc);
		if (nowc == '\n') break;
		pm[lenp] = nowc;
		lenp++;
	}

	int sum = num[0];
	int minus = 0;
	for (int i = 0; i <lenp; i++) {
		if (pm[i] == '+') {
			sum += num[i + 1];
		}
		else {
			minus = i + 1;
			break;
		}
	}
	if (minus > 0) {
		for (int i = minus; i <lenn; i++) {
			sum -= num[i];
		}
	}
	printf("%d", sum);
	

}