#include <stdio.h>



int main() {
	char longs[101];
	
	scanf("%s", &longs);
	printf("%c", longs[0]);
	for (int i = 0; i < 100; i++) {
		if (longs[i] == NULL) {
			break;
		}
		if (longs[i] == '-') {
			printf("%c", longs[i + 1]);
		}
	}



}