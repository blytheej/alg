#include <stdio.h>
#include <queue>
#include <stdlib.h>

int apt[26][26];
int now = -1;
int ave[626];
int n = 0;

int bfs(int x, int y) {
	ave[now]++;

	if (x > 0 && apt[x - 1][y] == 1) {
		apt[x - 1][y] = 0;
		bfs(x - 1, y);
	}
	if (x + 1 < n  && apt[x + 1][y] == 1) {
		apt[x + 1][y] = 0;
		bfs(x + 1, y);
	}
	if (y > 0 && apt[x][y - 1] == 1) {
		apt[x][y - 1] = 0;
		bfs(x, y - 1);
	}
	if (y + 1 < n && apt[x][y + 1] == 1) {
		apt[x][y + 1] = 0;
		bfs(x, y + 1);
	}
	return 0;
}


int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main() {

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &apt[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (apt[i][j] == 1) {
				now++;
				apt[i][j] = 0;
				bfs(i, j);
			}
		}
	}
	qsort(ave, sizeof(ave) / sizeof(int), sizeof(int), compare);
	
	if (now == -1) {
		printf("%d", 0);
	}
	else {
		printf("%d\n", now + 1);
		for (int i = 625 - now; i < 626; i++) {
			printf("%d\n", ave[i]);
		}
	}
	
	
}

