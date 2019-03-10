#include <stdio.h>
#include <algorithm>

struct map {
	int h;
	int x;
	int y;
};

bool cmp(map a, map b) {
	return a.h > b.h;
}


int main() {


	int n, m;
	scanf("%d %d", &n, &m);

	map high[25002];
	int id =0;
	int map[501][501];
	long long int way[501][501] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			high[id].h = map[i][j];
			high[id].x = i;
			high[id].y = j;
			id++;
		}
	}
	way[0][0] = 1;
	std::sort(high, high + id, cmp);

	
	int h, x, y;

	for (int i = 0; i < id; i++) {
		h = high[i].h;
		x = high[i].x;
		y = high[i].y;

		if (x > 0 && map[x - 1][y] < h) { way[x - 1][y] += way[x][y]; }
		if (x < n - 1 && map[x + 1][y] < h) { way[x + 1][y] += way[x][y]; }
		if (y > 0 && map[x][y - 1] < h) { way[x][y - 1] += way[x][y]; }
		if (y < m - 1 && map[x][y + 1] < h) { way[x][y + 1] += way[x][y]; }
	}



	printf("%lld", way[n - 1][m - 1]);

}