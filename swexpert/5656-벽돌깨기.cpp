#include <stdio.h>
#include <queue>
using namespace std;

int n, w, h;

int min_left;
queue<int> bw; //balls w, h
queue<int> bh;
queue<int> be;

int min(int a, int b) {
	return a < b ? a : b;
}



void drop(int m[13][17], int dropped) {

	if (min_left == 0) { return; }
	//printf("\n");
	//for (int i = h - 1; i >= 0; i--) {
	//   for (int j = 0; j < w; j++) {
	//      printf("%d ", m[i][j]);
	//   }
	//   printf("\n");
	//}

	if (dropped == n) {
		int left = 0;
		for (int i = h - 1; i >= 0; i--) {
			for (int j = 0; j < w; j++) {
				if (m[i][j] != 0) {
					left++;
				}
			}
		}
		min_left = min(min_left, left);
		return;
	}


	for (int b = 0; b < w; b++) { // b = ball 
		int cm[13][17];
		//map being changed
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cm[i][j] = m[i][j];
			}
		}
		//drop
		//first block
		bool clear_needed = false;
		for (int i = h - 1; i >= 0; i--) {
			if (cm[i][b] != 0) {
				if (cm[i][b] == 1) {
					cm[i][b] = 0;
					break;
				}
				else {
					bw.push(b);
					bh.push(i);
					be.push(cm[i][b] - 1);
					clear_needed = true;
					break;
				}
			}
		}
		int bx, by, e;
		//explode
		while (!bw.empty()) {
			bx = bw.front(); bw.pop();
			by = bh.front(); bh.pop();
			e = be.front();
			be.pop();


			//get explode range
			int l, r, u, d;
			l = bx - e; r = bx + e; u = by + e; d = by - e;
			if (l < 0) l = 0;
			if (r >= w) r = w - 1;
			if (u >= h) u = h - 1;
			if (d < 0) d = 0;
			//explode left to right
			for (int i = l; i <= r; i++) {
				int energy = cm[by][i];
				if (energy > 1) {
					bw.push(i); bh.push(by); be.push(energy - 1);
				}
				cm[by][i] = 0;
			}
			// explode up to down
			for (int i = d; i <= u; i++) {
				int energy = cm[i][bx];
				if (energy > 1) {
					bw.push(bx); bh.push(i); be.push(energy - 1);
				}
				cm[i][bx] = 0;
			}
		}
		//clear blanks
		int nums[20];
		if (clear_needed) {
			for (int i = 0; i < w; i++) {
				int num = 0;
				for (int k = 0; k < h; k++) {
					if (cm[k][i] > 0) {
						nums[num] = cm[k][i];
						num++;
					}
				}
				for (int k = 0; k < h; k++) {
					if (k < num) {
						cm[k][i] = nums[k];
					}
					else {
						cm[k][i] = 0;
					}
				}
			}

		}

		// 
		drop(cm, dropped + 1);
	}

}



int main() {

	int test;
	scanf("%d", &test);

	for (int tc = 1; tc <= test; tc++) {
		int map[13][17];
		//reset
		min_left = 200;

		scanf("%d %d %d", &n, &w, &h);

		for (int i = h - 1; i >= 0; i--) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		drop(map, 0);

		printf("#%d %d\n", tc, min_left);

	}

}