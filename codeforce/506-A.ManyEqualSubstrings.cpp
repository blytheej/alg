#include <stdio.h>
#include <string.h>

int main() {
	int n, k = 0;
	scanf("%d %d", &n, &k);

	char strr[51]; //got string
	scanf("%s", &strr);

	int ntr = -1; // char need to repeat



	char* exist = strchr(strr+1, strr[0]);

	while (exist != NULL) {
		int start = int(exist - strr); // find char index
		bool repeat = true;
		for (int i = start; i < n; i++) {
			if (strr[i - start] != strr[i]) {
				repeat = false;
				break;
			}
		}
		if (repeat) { // repeated
			ntr = start;
			exist = NULL;
		}
		else {
			exist = strchr(exist + 1, strr[0]);
		}
	}
	if (ntr == -1) {
		for (int i = 0; i < k; i++) {
			printf("%s", strr);
		}
	}
	else {
		
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < ntr; j++) {
				printf("%c", strr[j]);
			}
		}
		for (int i = ntr; i < n; i++) {
			printf("%c", strr[i]);
		}
	}

}
