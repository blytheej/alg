#include <stdio.h>

int n;
int screen[65][65];

int quad(int x, int y, int len) {

	int wb = screen[x][y];
	bool check = true;

	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (screen[i][j] != wb) {
				check = false;
				break;
			}
		}
	}
	if (check) {
		printf("%d", wb);
		return 0;
	}
	
	printf("(");

	for (int i = x; i < x + len; i += len / 2) {
		for (int j = y; j < y + len; j += len / 2) {
			quad(i, j, len / 2);
		}
	}

	printf(")");


	return 0;

}

int main() {

	

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &screen[i][j]);
		}
	}

	quad(0, 0, n);


}