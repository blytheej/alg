#include <stdio.h>
#include <queue>

int tc;
int l; //체스판 길이
int board[301][301]; //체스판
int sx, sy, ex, ey;//시작 위치, 끝 위치

std::queue<int> b_x;
std::queue<int> b_y;

int reset() {
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			board[i][j] = 0;
		}
	}
	l = 0;
	sx = 0; sy = 0; ex = 0; ey = 0;
	while (!b_x.empty()) {
		b_x.pop();
		b_y.pop();
	}
	return 0;
}

int knight() {
	int x = b_x.front();
	int y = b_y.front();
	b_x.pop();
	b_y.pop();

	if (x - 2 >= 0 && y - 1 >= 0 && board[x - 2][y - 1] == 0) {
		b_x.push(x - 2);
		b_y.push(y - 1);
		board[x - 2][y - 1] = board[x][y] + 1;
	}
	if (x - 1 >= 0 && y - 2 >= 0 && board[x - 1][y - 2] == 0) {
		b_x.push(x - 1);
		b_y.push(y - 2);
		board[x - 1][y - 2] = board[x][y] + 1;
	}
	if (x + 1 < l && y - 2 >= 0 && board[x + 1][y - 2] == 0) {
		b_x.push(x + 1);
		b_y.push(y - 2);
		board[x + 1][y - 2] = board[x][y] + 1;
	}
	if (x + 2 < l && y - 1 >= 0 && board[x + 2][y - 1] == 0) {
		b_x.push(x + 2);
		b_y.push(y - 1);
		board[x + 2][y - 1] = board[x][y] + 1;
	}
	if (x + 2 < l && y + 1 < l && board[x + 2][y + 1] == 0) {
		b_x.push(x + 2);
		b_y.push(y + 1);
		board[x + 2][y + 1] = board[x][y] + 1;
	}
	if (x + 1 < l && y + 2 < l && board[x + 1][y + 2] == 0) {
		b_x.push(x + 1);
		b_y.push(y + 2);
		board[x + 1][y + 2] = board[x][y] + 1;
	}
	if (x - 1 >= 0 && y + 2 < l && board[x - 1][y + 2] == 0) {
		b_x.push(x - 1);
		b_y.push(y + 2);
		board[x - 1][y + 2] = board[x][y] + 1;
	}
	if (x - 2 >= 0 && y + 1 < l && board[x - 2][y + 1] == 0) {
		b_x.push(x - 2);
		b_y.push(y + 1);
		board[x - 2][y + 1] = board[x][y] + 1;
	}
	return 0;
}

int main() {

	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		reset();
		scanf("%d", &l);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &ex, &ey);
		b_x.push(sx);
		b_y.push(sy);
		board[sx][sy] = 1;

		if (sx == ex && sy == ey) {
			printf("%d", 0);
		}
		else {
			while (!b_x.empty()) {
				if (board[ex][ey] != 0) {
					break;
				}
				knight();
			}
			for (int a = 0; a <11; a++) {
				for (int j = 0; j < 11; j++) {
					printf("%d", board[a][j]);
				}
				printf("%s", "\n");
			}

			printf("%d\n", board[ex][ey]-1);
		}
	}
}