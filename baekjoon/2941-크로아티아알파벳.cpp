#include <stdio.h>

int main() {

	char cr[102];

	int n = 0;
	int letters = 0;
	scanf("%s", &cr);
	while (cr[n] != NULL) {

		if (cr[n] == 'c') {
			if (cr[n + 1] == '=') {
				n += 2;
			}
			else if (cr[n + 1] == '-') {
				n += 2;
			}
			else {
				n += 1;
			}
		}
		else if (cr[n] == 'd' ) {
			if (cr[n + 1] == 'z' && cr[n + 2] == '=') {
				n += 3;
			}
			else if (cr[n + 1] == '-') {
				n += 2;
			}
			else {
				n += 1;
			}
		}
		else if (cr[n] == 'l' && cr[n+1] =='j') {
			n += 2;
		}
		else if (cr[n] == 'n' && cr[n+1] =='j' ) {
			n += 2;
		}
		else if (cr[n] == 's' && cr[n + 1] == '=') {
			n += 2;
		}
		else if (cr[n] == 'z' && cr[n + 1] == '=') {
			n += 2;
		}
		else {
			n++;
		}
		letters++;
	}

	printf("%d", letters);
}