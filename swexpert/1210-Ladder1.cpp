#include <stdio.h>

int main() {

	int test;
	int lad[102][102];

	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &test);

		//get ladder
		for (int i = 1; i < 100; i++) {
			for (int j = 1; j <= 100; j++) {
				scanf("%d", &lad[i][j]);
			}
		}
		int start;
		for (int j = 1; j <= 100; j++) {
			scanf("%d", &lad[100][j]);
			if (lad[100][j] == 2) {
				start = j;
			}
		}
		
		int lev = 100;
		int num = start;
		while (lev != 1) {

			if (lad[lev][num - 1] == 1) {
				while (lad[lev][num - 1] == 1) {
					num--;
				}
				lev--;
			}
			else if (lad[lev][num + 1] == 1) {
				while (lad[lev][num + 1] == 1) {
					num++;
				}
				lev--;
			}
			else {
				lev--;
			}
		}

		printf("#%d %d\n", test,num-1);


	}


}