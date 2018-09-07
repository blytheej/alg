#include <stdio.h>



int isParil(char a, char b) {

	bool same = true;
	int diff = (a - b);
	if (!(diff == 0 || diff == -2 || diff == 2)) {
		same = false;
	}
	return same;
}


int main() {
	
	int tc;
	scanf("%d", &tc);
	
	char par[102];
	int len;

	for (int t = 0; t < tc; t++) {
		scanf("%d %s", &len, &par);

		bool twParil = true;
		for (int i = 0; i < len / 2; i++) {
			if (!isParil(par[i], par[len - 1 - i])) {
				twParil = false;
				break;
			}


		}
		if (twParil) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

}