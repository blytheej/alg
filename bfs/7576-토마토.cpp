#include <stdio.h>
#include <queue>

int n, m;
int box[1010][1010];
int days = 0;

std::queue<int> b_x;
std::queue<int> b_y;

int ripe() {
	int x = b_x.front();
	int y = b_y.front();
	b_x.pop();
	b_y.pop();
	if (x > 0 && box[x - 1][y] == 0) {
		b_x.push(x - 1);
		b_y.push(y);
		box[x - 1][y] = box[x][y] + 1;
	}
	if (x +1 < n && box[x + 1][y] == 0) {
		b_x.push(x + 1);
		b_y.push(y);
		box[x + 1][y] = box[x][y] + 1;
	}
	if (y > 0 && box[x][y - 1] == 0) {
		b_x.push(x);
		b_y.push(y - 1);
		box[x][y - 1] = box[x][y] + 1;
	}
	if (y + 1 < m && box[x][y + 1] == 0) {
		b_x.push(x);
		b_y.push(y + 1);
		box[x][y + 1] = box[x][y] + 1;
	}


	return 0;
}

int main() {

	scanf("%d %d", &m, &n);
	
	bool all_ripe = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 0) {
				all_ripe = false;
			}
			else if (box[i][j] == 1) {
				b_x.push(i);
				b_y.push(j);
			}
		}
	}
	if (all_ripe) {
		printf("%d", days);
		return 0;
	}
	while (!b_x.empty()) {
		ripe();
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int today = box[i][j];
			if (today == 0) {
				printf("%d", -1);
				return 0;
			}
			else {
				if (today > days) {
					days = today;
				}
			}
		}
	}

	printf("%d", days - 1);
	
	return 0;

}