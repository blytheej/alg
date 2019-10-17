#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, l, r;
int map[53][53];
int day;
bool moved;

queue<int> b_x;
queue<int> b_y;

int opened = 0;
int open_sum[2500] = { 0, };
int open_size[2500];

int cmap[52][52] = { 0, };

bool diff_in(int a, int b) {
	if (a - b <= r && a - b >= l) {
		return true;
	}
	else if (b - a <= r && b - a >= l) {
		return true;
	}
	else {
		return false;
	}
}

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cmap[i][j] = 0;
		}
	}
	for (int i = 0; i < 2500; i++) {
		open_sum[i] = 0;
	}

}

//open the door  
void open(int a, int b) {

	int num = 0;
	b_x.push(a);
	b_y.push(b);
	cmap[a][b] = -1;

	int group = opened + 1;

	while (!b_x.empty()) {
		num++;
		int x = b_x.front(); b_x.pop();
		int y = b_y.front(); b_y.pop();

		int pop = map[x][y];

		//check 4 ways to open
		if (x>0 && cmap[x-1][y]==0 && diff_in(pop, map[x-1][y])) {
			cmap[x - 1][y] = group;
			open_sum[group] += map[x - 1][y];
			b_x.push(x - 1);
			b_y.push(y);
		}
		if (x < n - 1 && cmap[x + 1][y] == 0 && diff_in(pop, map[x + 1][y])) {
			cmap[x + 1][y] = group;
			open_sum[group] += map[x + 1][y];
			b_x.push(x + 1);
			b_y.push(y);
		}
		if (y > 0 && cmap[x ][y - 1] == 0 && diff_in(pop, map[x][y - 1])) {
			cmap[x ][y - 1] = group;
			open_sum[group] += map[x][y  -1];
			b_x.push(x);
			b_y.push(y - 1);
		}
		if (y < n-1 && cmap[x ][y + 1] == 0 && diff_in(pop, map[x][y + 1])) {
			cmap[x][y + 1] = group;
			open_sum[group] += map[x][y + 1];
			b_x.push(x);
			b_y.push(y + 1);
		}

	}
	//if connected is more than 1
	if (num > 1) {
		opened++;
		open_sum[opened] += map[a][b];
		open_size[opened] = num;
		cmap[a][b] = opened;

	}
	return;

}

void move() {

	opened = 0;
	clear();
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cmap[i][j] == 0) {
				open(i, j);
			}
		}
	}

	if (opened > 0) {
		moved = true;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int grp = cmap[i][j];
				if (grp > 0) {
					map[i][j] = open_sum[grp] / open_size[grp];
				}
			}
		}


	}
}



int main() {

	scanf("%d %d %d", &n, &l, &r);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}


	day = 0;
	moved = true;

	while (moved) {
		moved = false;
		move();
		
		if (moved) {
			day++;
		}
		else {
			break;
		}

	}
	

	printf("%d", day);


}