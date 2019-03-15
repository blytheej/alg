#include <stdio.h>
#include <queue>
using namespace std;

int area[60][60] = { 0, };
int w, h;
queue<int> x;
queue<int> y;



void bfs() {

	int cx = x.front(); x.pop();
	int cy = y.front(); y.pop();


	if (area[cx - 1][cy] == 1) {
		area[cx - 1][cy] = 0;
		x.push(cx - 1); y.push(cy);
	}
	if (area[cx + 1][cy] == 1) {
		area[cx + 1][cy] = 0;
		x.push(cx + 1); y.push(cy);
	}
	if (area[cx ][cy -1] == 1) {
		area[cx ][cy-1] = 0;
		x.push(cx); y.push(cy - 1);
	}
	if (area[cx][cy +1] == 1) {
		area[cx][cy +1] = 0;
		x.push(cx); y.push(cy+1);
	}
	if (area[cx -1][cy - 1] == 1) {
		area[cx - 1][cy - 1] = 0;
		x.push(cx-1); y.push(cy - 1);
	}
	if (area[cx - 1][cy + 1] == 1) {
		area[cx - 1][cy + 1] = 0;
		x.push(cx-1); y.push(cy + 1);
	}
	if (area[cx + 1][cy + 1] == 1) {
		area[cx + 1][cy + 1] = 0;
		x.push(cx+1); y.push(cy + 1);
	}
	if (area[cx + 1][cy - 1] == 1) {
		area[cx + 1][cy - 1] = 0;
		x.push(cx+1); y.push(cy - 1);
	}
	return;

}


int main() {

	while (true) {

		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			break;
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &area[i][j]);
			}
		}

		int land = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (area[i][j] == 1) {
					area[i][j] = 0;
					land++;

					x.push(i);
					y.push(j);

					while (!x.empty()) {
						bfs();
					}
				}
			}
		}
		printf("%d\n", land);

	}


}