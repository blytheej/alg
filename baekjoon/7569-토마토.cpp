#include <stdio.h>
#include <queue>
using namespace std;

int main() {

	int n, m, h;
	scanf("%d %d %d", &m, &n, &h);

	int to[102][102][102];
	queue<int> x;
	queue<int> y;
	queue<int> z;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &to[i][j][k]);
				if (to[i][j][k] == 1) {
					x.push(i); y.push(j); z.push(k);
				}
			}

		}
	}
	
	int a, b, c;
	int days = 0;
	while (!x.empty()) {
		a = x.front(); x.pop();
		b = y.front(); y.pop();
		c = z.front(); z.pop();
		int day = to[a][b][c];
		if (day > days) { days = day; }
		if (a > 0 && !to[a - 1][b][c]) {
			to[a - 1][b][c] = day + 1;
			x.push(a - 1); y.push(b); z.push(c);
		}
		if (a < n -1 &&!to[a + 1][b][c]) {
			to[a + 1][b][c] = day + 1;
			x.push(a + 1); y.push(b); z.push(c);
		}
		if (b > 0 && !to[a][b -1][c]) {
			to[a][b -1][c] = day + 1;
			x.push(a); y.push(b-1); z.push(c);
		}
		if (b < m - 1&& !to[a][b+1][c]) {
			to[a][b+1][c] = day + 1;
			x.push(a); y.push(b+1); z.push(c);
		}
		if (c > 0 && !to[a][b][c - 1]) {
			to[a][b][c - 1] = day + 1;
			x.push(a); y.push(b); z.push(c - 1);
		}
		if (c <h -1 && !to[a][b][c + 1]) {
			to[a][b][c + 1] = day + 1;
			x.push(a); y.push(b); z.push(c + 1);
		}

	}

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (to[i][j][k] == 0) {
					days = 0;
				}
			}

		}
	}
	printf("%d", days - 1);


}