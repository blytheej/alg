#include <stdio.h>


bool cmp(int a[52], int b[52]) {
	bool same = true;

	for (int i = 0; i < 52; i++) {
		if (a[i] != b[i]) {
			same = false;
			break;
		}
	}
	return same;
}


int main() {

	int tc;
	scanf("%d", &tc);


	for (int test = 1; test <= tc; test++) {


		int n, m;
		scanf("%d %d", &n, &m);

		int color[52] = { 0, };
		int cnt=0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &color[i]);
			cnt += color[i];
		}
		
		int car[1002];
		for (int i = 0; i < n; i++) {
			scanf("%d", &car[i]);
			car[i]--;
		}
		int wh = 0;
		for (int i = 0; i <= n-cnt; i++) {
			if (color[car[i]] > 0) {
				int c[52] = { 0, };
				for (int s = 0; s < cnt; s++) {
					c[car[i + s]]++;
				}
				if (cmp(color, c)) {
					wh = i + 1;
					break;
				}
			}
			

		}
		printf("#%d %d\n", test, wh);
	}
}