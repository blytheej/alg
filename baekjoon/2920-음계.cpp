#include <stdio.h>

int main() {

	int s[8];

	for (int i = 0; i < 8; i++) {
		scanf("%d", &s[i]);
	}
	
	
	int what = 0;

	if (s[0] == 1) {
		what = 1;
		for (int i = 1; i < 8; i++) {
			if (s[i] != i + 1) {
				what = 0; break;
			}
		}
	}
	else if (s[0] == 8) {
		what = 2;
		for (int i = 1; i < 8; i++) {
			if (s[i] != 8 - i) {
				what = 0; break;
			}
		}
	}

	if (what == 0) {
		printf("mixed");
	}
	else if (what == 1) {
		printf("ascending");
	}
	else{
		printf("descending");
	}
	
}