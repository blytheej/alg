#include <stdio.h>
#include <queue>

int n = 0, m = 0;
char map[51][51];
char far[51][51]; //¸Ê visit
int furthest = 0;// furthest route
int howfar = 0; //how far from start
std::queue<int> f_x;
std::queue<int> f_y;


int reset() {
	howfar = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			far[i][j] = 0;
		}
	}
	while (!f_x.empty()) {
		f_x.pop();
		f_y.pop();
	}
	return 0;
}

int get_far() {
	int x = f_x.front();
	int y = f_y.front();
	f_x.pop();
	f_y.pop();
	if (far[x][y] - 1 > howfar) {
		howfar = far[x][y] - 1;
	}

	if (x > 0 && map[x - 1][y] == 'L' && far[x - 1][y] == 0) {
		far[x - 1][y] = far[x][y] + 1;
		f_x.push(x - 1);
		f_y.push(y);
	}
	if (x + 1 < n && map[x + 1][y] == 'L' && far[x + 1][y] == 0) {
		far[x + 1][y] = far[x][y] + 1;
		f_x.push(x + 1);
		f_y.push(y);
	}
	if (y > 0 && map[x][y - 1] == 'L' && far[x][y - 1] == 0) {
		far[x][y - 1] = far[x][y] + 1;
		f_x.push(x);
		f_y.push(y - 1);
	}
	if (y + 1 < m && map[x][y + 1] == 'L' && far[x][y + 1] == 0) {
		far[x][y + 1] = far[x][y] + 1;
		f_x.push(x);
		f_y.push(y + 1);
	}
	return 0;
}

int main() {
	char enter;
	scanf("%d %d", &n, &m);
	//input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map[i][j]);
		}
		scanf("%c", &enter);
	}


	//get_furthest
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				reset();
				far[i][j] = 1;
				f_x.push(i);
				f_y.push(j);
				while (!f_x.empty()) {
					get_far();
				}
				if (howfar > furthest) {
					furthest = howfar;
				}
			}
		}
	}


	printf("%d", furthest);

	return 0;
}