#include <stdio.h>

int main() {
	char a[17];
	int time = 0;
	scanf("%s", &a);

	for (int i = 0; i < 17; i++) {
		if (a[i] == NULL) break;

		else if (a[i] == 'A' || a[i] == 'B' || a[i] == 'C') {
			time += 3;
		}
		else if (a[i] == 'D' || a[i] == 'E' || a[i] == 'F') {
			time += 4;
		}
		else if (a[i] == 'G' || a[i] == 'H' || a[i] == 'I') {
			time += 5;
		}
		else if (a[i] == 'J' || a[i] == 'K' || a[i] == 'L') {
			time += 6;
		}
		else if (a[i] == 'M' || a[i] == 'N' || a[i] == 'O') {
			time += 7;
		}
		else if (a[i] == 'P' || a[i] == 'Q' || a[i] == 'R' || a[i] == 'S') {
			time += 8;
		}
		else if (a[i] == 'T' || a[i] == 'U' || a[i] == 'V') {
			time += 9;
		}
		else  {
			time += 10;
		}
	}

	printf("%d", time);
}