#include <stdio.h>

int main() {

	int tc;
	scanf("%d", &tc);

	while (tc--) {

		char rw[81];
		scanf("%s", rw);
		
		int score[81];
		int sum = 0;
		int i = 1;
		if (rw[0] == 'X') {
			score[0] = 0;
		}
		else {
			score[0] = 1;
			sum += 1;
		}

		while (rw[i] == 'X' || rw[i] == 'O') {
		
			if (rw[i] == 'X') {
				score[i] = 0;
			}
			else {
				score[i] = score[i - 1] + 1;
				sum += score[i];
			}
			i++;
		}

		printf("%d\n", sum);

	}

}