#include <stdio.h>

int main() {

	int test;
	int lad[102][102];

	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &test);

		//get ladder
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				scanf("%d", &lad[i][j]);
			}
		}
		int shortest = 1000000;
		int shidx = -1;
		for (int i = 1; i <= 100; i++) {
			if (lad[1][i] == 1) {

				int lev = 1;
				int now = i;
				int move = 0;
				while (lev != 100) {

					if (lad[lev][now + 1] == 1) {
						while (lad[lev][now + 1] == 1) {
							now++;
							move++;
						}
						lev++;
						move++;
					}
					else if (lad[lev][now - 1] == 1) {
						while (lad[lev][now - 1] == 1) {
							now--;
							move++;
						}
						lev++;
						move++;
					}
					else {
						lev++;
						move++;
					}
				}
				if (move <= shortest) {
					shortest = move;
					shidx = i;
				}
				
			}
		}

		printf("#%d %d\n", test, shidx - 1);


	}


}