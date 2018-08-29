#include <stdio.h>

int main() {

	int n = 0;
	scanf("%d", &n);

	int drink = 0;
	int havetodrink = 0;

	while (n--) {
		int now;
		scanf("%d", &now);
		if (now == havetodrink) {
			drink++;
			havetodrink++;
			if (havetodrink > 2) havetodrink = 0;
		}
	}
	printf("%d", drink);
}