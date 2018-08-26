#include <stdio.h>
#include <queue>

int n = 0;
char area[101][101];
char areab[101][101];
int areas = 0;
int areabs = 0;

//dfs 이용
//not cb
int get_area(int x, int y, char z) {
	if (x > 0 && area[x - 1][y] == z) {
		area[x - 1][y] = 'N';
		get_area(x - 1, y, z);
	}
	if (x + 1 < n  && area[x + 1][y] == z) {
		area[x + 1][y] = 'N';
		get_area(x + 1, y, z);
	}
	if (y > 0 && area[x][y - 1] == z) {
		area[x][y - 1] = 'N';
		get_area(x, y - 1, z);
	}
	if (y + 1 < n && area[x][y + 1] == z) {
		area[x][y + 1] = 'N';
		get_area(x , y + 1, z);
	}
	return 0;
}
//color-blind
int get_areab(int x, int y, char z) {
	if (x > 0 && areab[x - 1][y] == z) {
		areab[x - 1][y] = 'N';
		get_areab(x - 1, y, z);
	}
	if (x + 1 < n  && areab[x + 1][y] == z) {
		areab[x + 1][y] = 'N';
		get_areab(x + 1, y, z);
	}
	if (y > 0 && areab[x][y - 1] == z) {
		areab[x][y - 1] = 'N';
		get_areab(x, y - 1, z);
	}
	if (y + 1 < n && areab[x][y + 1] == z) {
		areab[x][y + 1] = 'N';
		get_areab(x, y + 1, z);
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	// 입력 받기
	char s;
	char enter;
	for (int i = 0; i < n; i++) {
		scanf("%1c", &enter);
		for (int j = 0; j < n; j++) {
			scanf("%1c", &s);
			area[i][j] = s;
			if (s == 'G') {
				areab[i][j] = 'R';
			}else {
				areab[i][j] = s;
			}
		}
	}
	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char start = area[i][j];
			char startb = areab[i][j];
			if (start != 'N') {
				areas++;
				area[i][j] = 'N';
				get_area(i, j, start);
			}
			if (startb != 'N') {
				areabs++;
				areab[i][j] = 'N';
				get_areab(i, j, startb);
			}

		}
	}
	
	printf("%d %d", areas, areabs);

	return 0;
}