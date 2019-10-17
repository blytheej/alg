#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int m, a;
int move_a[102], move_b[102];
int bc_x[10], bc_y[10], bc_c[10], bc_p[10];

int max(int a, int b) {
	return a > b ? a : b;
}

int move_x(int x, int dir) {
	if (dir == 0) {
		return x;
	}
	else if (dir == 1) {
		return x - 1;
	}
	else if (dir == 2) {
		return x;
	}
	else if (dir == 3) {
		return x + 1;
	}
	else {
		return x ;
	}
}
int move_y(int y, int dir) {
	if (dir == 0) {
		return y;
	}
	else if (dir == 1) {
		return y;
	}
	else if (dir == 2) {
		return y + 1;
	}
	else if (dir == 3) {
		return y;
	}
	else {
		return y - 1;
	}
}

int get_charge(int ax, int ay, int bx, int by) {
	int max_charge = 0;
	int able[10][2] = { 0, };

	for (int i = 0; i < a; i++) {
		int diff_a = abs(bc_x[i] - ax) + abs(bc_y[i] - ay);
		int diff_b = abs(bc_x[i] - bx) + abs(bc_y[i] - by);

		if (diff_a <= bc_c[i]) {
			able[i][0] = bc_p[i];
		}
		if ( diff_b <= bc_c[i]) {
			able[i][1] = bc_p[i];
		}

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				if (i == j) {
					max_charge = max(max_charge, max(able[i][0],able[j][1]));
				}
				else {
					max_charge = max(max_charge, able[i][0] + able[j][1]);
				}
			}
		}
	}

	return max_charge;
}

int main() {

	int test;
	scanf("%d", &test);

	for (int tc = 1; tc <= test; tc++) {
		scanf("%d %d", &m, &a);

		int charge = 0;

		for (int i = 0; i < m; i++) {
			scanf("%d", &move_a[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &move_b[i]);
		}
		for (int i = 0; i < a; i++) {
			scanf("%d %d %d %d", &bc_y[i], &bc_x[i], &bc_c[i], &bc_p[i]);
		}

		int time = 0;
		int ax = 1, ay = 1, bx = 10, by = 10;
		while (time<=m) {
			//printf("time %d | %d %d %d %d\n",time, ax, ay, bx, by);
			charge += get_charge(ax, ay, bx, by);
			printf("%d ", get_charge(ax, ay, bx, by));
			if (time == m) {
				break;
			}
			ax = move_x(ax, move_a[time]);
			ay = move_y(ay, move_a[time]);
			bx = move_x(bx, move_b[time]);
			by = move_y(by, move_b[time]);
			time++;
		}
		//printf("\n");

		printf("#%d %d\n", tc, charge);

	}
}