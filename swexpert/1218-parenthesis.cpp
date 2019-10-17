#include <stdio.h>

int main() {

	for (int test = 1; test <= 10; test++) {

		int par[8];

		int len;
		scanf("%d", &len);
		char p;

		for (int i = 0; i < 8; i++) {
			par[i] = 0;
		}

		for (int i = 0; i < len; i++) {
			scanf(" %c", &p);
			
			if (p == '{') {
				par[0]++;
			}
			else if (p == '}') {
				par[1]++;
			}
			else if (p == '(') {
				par[2]++;
			}
			else if (p == ')') {
				par[3]++;
			}
			else if (p == '[') {
				par[4]++;
			}
			else if (p == ']') {
				par[5]++;
			}
			else if (p == '<') {
				par[6]++;
			}
			else {
				par[7]++;
			}

		}

		if (par[0] == par[1] && par[2] == par[3] && par[4] == par[5] && par[6] == par[7]) {
			printf("#%d 1\n", test);
		}
		else {
			printf("#%d 0\n",test);
		}



	}

}