#include <stdio.h>

int n = 0;
int find[2];
int m = 0;
int family[101][101];
int far = -1; 
int dfs(int peo, int now) { // 현재 사람, 현재 촌수
	if (peo == find[1]) {
		far = now;
	}else {
		for (int i = 0; i < n; i++) {
			if (family[peo][i] == 1) {
				family[peo][i] = 0;
				family[i][peo] = 0;
				dfs(i, now + 1);
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d %d %d %d", &n, &find[0], &find[1], &m);
	find[0]--; find[1]--;
	if (find[0] == find[1]) {
		printf("%d", 0);
		return 0;
	}
	
	int rela = 0;
	int relb = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &rela, &relb);
		family[rela-1][relb-1] = 1;
		family[relb-1][rela-1] = 1;
	}
	dfs(find[0], 1);
	if (far < 0) {
		printf("%d", -1);
	}
	else {
		printf("%d", far - 1);
	}

}