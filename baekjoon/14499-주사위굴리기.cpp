#include <stdio.h>


struct dice {

	int t;//top
	int b;//bottom
	int u;//up
	int l;//left
	int r;//right
	int d;//down
};

int t[7];
dice d = { 0,0,0,0,0,0};

int n, m, x, y, ks;
int k[1003];
int map[22][22];

void turn(int dir) {
	

	if (dir == 1) {
		t[1] = d.l; t[6] = d.r; t[3] = d.t; t[4] = d.b;
		d.t = t[1]; d.b = t[6];	d.r = t[3];	d.l = t[4];
	}
	if (dir == 2) {
		t[1] = d.r; t[6] = d.l; t[3] = d.b; t[4] = d.t;
		d.t = t[1]; d.b = t[6];	d.r = t[3];	d.l = t[4];
	}
	if (dir == 3) {
		t[1] = d.d; t[6] = d.u; t[2] = d.t; t[5] = d.b ;
		d.t = t[1]; d.b = t[6];	d.u = t[2];	d.d = t[5];
	}
	if (dir == 4) {
		t[1] = d.u; t[6] = d.d; t[2] = d.b; t[5] = d.t;
		d.t = t[1]; d.b = t[6];	d.u = t[2];	d.d = t[5];
	}
	return;
}

void move() {
	if (map[x][y] == 0) {
		map[x][y] = d.b;
	}
	else {
		d.b = map[x][y];
		map[x][y] = 0;
	}
	printf("%d\n", d.t);
}

int main() {

	scanf("%d %d %d %d %d", &n, &m, &x, &y, &ks);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < ks; i++) {
		scanf("%d", &k[i]);
	}

	for (int i = 0; i < ks; i++) {

		if (k[i] == 1 && y + 1 < m) {
			y++;
			turn(1);
			move();
		}
		if (k[i] == 2 && y - 1 >= 0) {
			y--;
			turn(2);
			move();
		}
		if (k[i] == 3 & x - 1 >= 0) {
			x--;
			turn(3);
			move();
		}
		if (k[i] == 4 && x + 1 < n) {
			x++;
			turn(4);
			move();
		}

	}


}