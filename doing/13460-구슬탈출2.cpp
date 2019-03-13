#include <stdio.h>

int n, m;
char map[12][12];
int min_move = -1;
int x1, y1, x2, y2, gx, gy;

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

void move(int rx, int ry, int bx, int by, int moves) {
	//stop recursion
	if (moves > 10 || ( min_move != -1 && moves > min_move )) {
		return;
	}
	if (bx == gx && by == gy) {
		return;
	}
	if (rx == gx && ry == gy ) {
		if (min_move == -1) {
			min_move = moves;
		}
		else {
			min_move = min(min_move, moves);
		}
		return;
	}

	int mrx, mry, mbx, mby; 
	bool stopr, stopb;
	
	//move left
	mry = ry; mby = by; stopr = false; stopb = false;

	while (true) {
		if (!stopr && map[rx][mry - 1] == '.') {
			if (mry - 1 != mby || (mry - 1 == mby && map[rx][mry - 2] == '.')) {
				mry--;
			}
			else if(mry - 1 == mby && map[rx][mry - 2] == '#')  {
			stopr = true;
			}
		}
		 else if(map[rx][mry-1] == 'O') {
			stopr = true;
			mry--;
		}
		else {
			stopr = true;
		}

		if (!stopb && map[bx][mby - 1] == '.') {
			if (mby - 1 != mry || (mby - 1 == mry && map[bx][mby - 2] == '.')) {
				mby--;
			}
			else if (mby - 1 == mry && map[bx][mby - 2] == '#') {
				stopb = true;
			}
		}
		else if (map[bx][mby - 1] == 'O') {
			stopb = true;
			mby--;
		}
		else {
			stopb = true;
		}
		
		printf("%d %d \n", stopr, stopb);
		if (stopr && stopb) {
			break;
		}
	}
	printf("%d : moved left %d %d %d %d \n", moves + 1, rx, mry, bx, mby);
	move(rx, mry, bx, mby, moves + 1);
	
	
	//move right
	mry = ry; mby = by; stopr = false; stopb = false;

	while (true) {
		if (!stopr && map[rx][mry + 1] == '.') {
			if (mry + 1 != mby || (mry + 1 == mby && map[rx][mry + 2] == '.')) {
				mry++;
			}
			else if (mry + 1 == mby && map[rx][mry + 2] == '#') {
				stopr = true;
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
			if (mby + 1 != mry || (mby + 1 == mry && map[bx][mby + 2] == '.')) {
				mby++;
			}
			else if (mby + 1 == mry && map[bx][mby + 2] == '#') {
				stopb = true;
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
	printf("%d : moved right %d %d %d %d \n", moves + 1, rx, mry, bx, mby);
	move(rx, mry, bx, mby, moves + 1);
	

	mry = ry; mby = by;

	//move up
	mrx = rx; mbx = bx; stopr = false; stopb = false;

	while (true) {
		if (!stopr && map[mrx - 1][ry] == '.' ){
			if (mrx - 1 != mbx || mrx - 1 == mbx && map[mrx - 2][ry] == '.') {
				mrx--;
			}
			else if (mrx - 1 == mbx && map[mrx - 2][ry] == '#') {
				stopr = true;
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
			if (mbx - 1 != mrx || mbx - 1 == mrx && map[mbx - 2][by] == '.') {
				mbx--;
			}
			else if (mbx - 1 == mry && map[mbx - 2][by] == '#') {
				stopb = true;
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
	printf("%d : moved up %d %d %d %d -> %d %d %d %d  \n", moves + 1,rx,ry,bx,by, mrx, ry, mbx, by);
	move(mrx, ry, mbx, by, moves + 1);
	
	//move down

	mrx = rx; mbx = bx; stopr = false; stopb = false;

	while (true) {
		if (!stopr && map[mrx + 1][ry] == '.') {
			if (mrx + 1 != mbx || mrx + 1 == mbx && map[mrx + 2][ry] == '.') {
				mrx++;
			}
			else if (mrx + 1 == mbx && map[mrx + 2][ry] == '#') {
				stopr = true;
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
			if (mbx + 1 != mrx || mbx + 1 == mrx && map[mbx + 2][by] == '.') {
				mbx++;
			}
			else if (mbx + 1 == mrx && map[mbx + 2][by] == '#') {
				stopb = true;
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
	printf("%d : moved down %d %d %d %d -> %d %d %d %d  \n", moves + 1, rx, ry, bx, by, mrx, ry, mbx, by);
	move(mrx, ry, mbx, by, moves + 1);
	
}


int main() {


	
	scanf("%d %d", &n, &m);


	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			map[i][j] = '#';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R') {
				x1 = i; y1 = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				x2 = i; y2 = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'O') {
				gx = i; gy = j;
			}
		}
	}

	move(x1, y1, x2, y2, 0);

	printf("%d", min_move);


}