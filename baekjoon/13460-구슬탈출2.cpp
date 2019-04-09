#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
char map[12][12];
queue<int> qrx, qry, qbx, qby;
int gx, gy;
int visited[12][12][12][12];
int min_move = 1000;


int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}


void move(int rx, int ry, int bx, int by) {

	//printf("%d : %d %d %d %d \n", visited[rx][ry][bx][by], rx, ry, bx, by);

	//stop recursion
	
	if (rx == gx && ry == gy) {
		while (!qrx.empty()) {
			qrx.pop();
		}
		return;
	}

	if (visited[rx][ry][bx][by] > 11) {
		return;
	}


	int mrx, mry, mbx, mby;
	bool stopr, stopb;

	//move left
	mry = ry; mby = by; stopr = false; stopb = false;

	while (true) {
		if (!stopr && map[rx][mry - 1] == '.') {
			if (rx != bx) {
				mry--;
			}
			else {
				if (mry - 1 != mby || (mry - 1 == mby && map[rx][mry - 2] == '.')) {
					mry--;
				}
				else if (mry - 1 == mby && map[rx][mry - 2] == '#') {
					stopr = true;
				}
			}
		}
		else if (map[rx][mry - 1] == 'O') {
			stopr = true;
			mry--;
		}
		else {
			stopr = true;
		}

		if (!stopb && map[bx][mby - 1] == '.') {
			if (rx != bx) {
				mby--;
			}
			else {
				if (mby - 1 != mry || (mby - 1 == mry && map[bx][mby - 2] == '.')) {
					mby--;
				}
				else if (mby - 1 == mry && map[bx][mby - 2] == '#') {
					stopb = true;
				}
			}
		}
		else if (map[bx][mby - 1] == 'O') {
			stopb = true;
			mby--;
		}
		else {
			stopb = true;
		}

		if (stopr && stopb) {
			break;
		}
	}

	if (!visited[rx][mry][bx][mby] && (bx!=gx || mby!=gy) ) {
		//printf(" moved left %d %d %d %d -> %d %d %d %d \n", rx, ry, bx, by, rx, mry, bx, mby);
		qrx.push(rx); qry.push(mry); qbx.push(bx); qby.push(mby);
		visited[rx][mry][bx][mby] = visited[rx][ry][bx][by] + 1;
	}
	//move right
	mry = ry; mby = by; stopr = false; stopb = false;

	while (true) {
		if (!stopr && map[rx][mry + 1] == '.') {
			if (rx != bx) {
				mry++;
			}
			else {
				if (mry + 1 != mby || (mry + 1 == mby && map[rx][mry + 2] == '.')) {
					mry++;
				}
				else if (mry + 1 == mby && map[rx][mry + 2] == '#') {
					stopr = true;
				}
			}
		}
		else if (map[rx][mry + 1] == 'O') {
			stopr = true;
			mry++;
		}
		else {
			stopr = true;
		}

		if (!stopb && map[bx][mby + 1] == '.') {
			if (rx != bx) {
				mby++;
			}
			else {
				if (mby + 1 != mry || (mby + 1 == mry && map[bx][mby + 2] == '.')) {
					mby++;
				}
				else if (mby + 1 == mry && map[bx][mby + 2] == '#') {
					stopb = true;
				}
			}
		}
		else if (map[bx][mby + 1] == 'O') {
			stopb = true;
			mby++;
		}
		else {
			stopb = true;
		}

		if (stopr && stopb) {
			break;
		}
	}

	if (!visited[rx][mry][bx][mby] && (bx != gx || mby != gy)) {
		//printf(" moved right %d %d %d %d -> %d %d %d %d \n", rx, ry, bx, by, rx, mry, bx, mby);
		qrx.push(rx); qry.push(mry); qbx.push(bx); qby.push(mby);
		visited[rx][mry][bx][mby] = visited[rx][ry][bx][by] + 1;
	}


	mry = ry; mby = by;
	//move up
	mrx = rx; mbx = bx; stopr = false; stopb = false;

	while (true) {
		if (!stopr && map[mrx - 1][ry] == '.') {
			if (ry != by) {
				mrx--;
			}
			else {
				if (mrx - 1 != mbx || mrx - 1 == mbx && map[mrx - 2][ry] == '.') {
					mrx--;
				}
				else if (mrx - 1 == mbx && map[mrx - 2][ry] == '#') {
					stopr = true;
				}
			}
		}
		else if (map[mrx - 1][ry] == 'O') {
			stopr = true;
			mrx--;
		}
		else {
			stopr = true;
		}

		if (!stopb && map[mbx - 1][by] == '.') {
			if (ry != by) {
				mbx--;
			}
			else {
				if (mbx - 1 != mrx || mbx - 1 == mrx && map[mbx - 2][by] == '.') {
					mbx--;
				}
				else if (mbx - 1 == mrx && map[mbx - 2][by] == '#') {
					stopb = true;
				}
			}
		}
		else if (map[mbx - 1][by] == 'O') {
			stopb = true;
			mbx--;
		}
		else {
			stopb = true;
		}

		if (stopr && stopb) {
			break;
		}
	}

	if (!visited[mrx][ry][mbx][by] && (mbx != gx || by != gy)) {
		//printf(" moved up %d %d %d %d -> %d %d %d %d \n", rx, ry, bx, by, rx, mry, bx, mby);
		qrx.push(mrx); qry.push(ry); qbx.push(mbx); qby.push(by);
		visited[mrx][ry][mbx][by] = visited[rx][ry][bx][by] + 1;
	}

		//move down

	mrx = rx; mbx = bx; stopr = false; stopb = false;

		while (true) {
			if (!stopr && map[mrx + 1][ry] == '.') {
				if (ry != by) {
					mrx++;
				}
				else {
					if (mrx + 1 != mbx || mrx + 1 == mbx && map[mrx + 2][ry] == '.') {
						mrx++;
					}
					else if (mrx + 1 == mbx && map[mrx + 2][ry] == '#') {
						stopr = true;
					}
				}
			}
			else if (map[mrx + 1][ry] == 'O') {
				stopr = true;
				mrx++;
			}
			else {
				stopr = true;
			}

			if (!stopb && map[mbx + 1][by] == '.') {
				if (ry != by) {
					mbx++;
				}
				else {
					if (mbx + 1 != mrx || mbx + 1 == mrx && map[mbx + 2][by] == '.') {
						mbx++;
					}
					else if (mbx + 1 == mrx && map[mbx + 2][by] == '#') {
						stopb = true;
					}
				}
			}
			else if (map[mbx + 1][by] == 'O') {
				stopb = true;
				mbx++;
			}
			else {
				stopb = true;
			}

			if (stopr && stopb) {
				break;
			}
		}

		if (!visited[mrx][ry][mbx][by] && (mbx != gx || by != gy)) {
			//printf(" moved down %d %d %d %d -> %d %d %d %d \n", rx, ry, bx, by, rx, mry, bx, mby);
			qrx.push(mrx); qry.push(ry); qbx.push(mbx); qby.push(by);
			visited[mrx][ry][mbx][by] = visited[rx][ry][bx][by] + 1;
		}
	}
	

int main() {



	scanf("%d %d", &n, &m);


	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			map[i][j] = '#';
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			for (int l = 0; l < 12; l++) {
				for (int k = 0; k < 12; k++) {
					visited[i][j][l][k];
				}
			}
		}
	}

	int r1, r2, b1, b2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R') {
				qrx.push(i); qry.push(j);
				r1 = i, r2 = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				qbx.push(i); qby.push(j);
				b1 = i; b2 = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'O') {
				gx = i; gy = j;
			}
		}
	}

	visited[r1][r2][b1][b2] = 1;

	int x1, y1, x2, y2;
	while (!qrx.empty()) {
		x1 = qrx.front(); qrx.pop();
		x2 = qbx.front(); qbx.pop();
		y1 = qry.front(); qry.pop();
		y2 = qby.front(); qby.pop();
		move(x1, y1, x2, y2);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[gx][gy][i][j] != 0) {
				min_move = min(min_move, visited[gx][gy][i][j]);
			}
		}
	}
	
	if (min_move > 11)min_move = 0;
	printf("%d", min_move-1);


}