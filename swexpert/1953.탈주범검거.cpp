#include <stdio.h>
#include <queue>

using namespace std;


int pipe[8][4]=
{
	0,0,0,0, //x
	1,1,1,1, // +
	1,0,1,0, // -
	0,1,0,1, // |
	1,1,0,0, // ¤¤
	0,1,1,0, // | ¤Ñ  
	0,0,1,1,// ¤¡
	1,0,0,1 //  ¤Ñ |
};



int main() {

	int test;
	scanf("%d", &test);

	for (int tc = 1; tc <= test; tc++) {

		int map[51][51];
		int n, m, r, c, l;

		scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		queue<int> wh_x, wh_y;
		wh_x.push(r);
		wh_y.push(c);

		int space = 0;
		int visited[51][51] = { 0, };
		int x, y;
		visited[r][c] = 1;
		while (!wh_x.empty()) {

			x = wh_x.front(); wh_x.pop();
			y = wh_y.front(); wh_y.pop();
			int vis = visited[x][y];
			
			int p = map[x][y];
			//check up
			if (x>0 && pipe[p][0] && pipe[map[x-1][y]][2] && visited[x-1][y] == 0 ) {

				visited[x - 1][y] = vis + 1;
				wh_x.push(x - 1);
				wh_y.push(y);
			}

			//check right 
			if (y < m-1 && pipe[p][1] && pipe[map[x][y + 1]][3] && visited[x][y + 1] == 0) {

				visited[x][y + 1] = vis + 1;
				wh_x.push(x);
				wh_y.push(y + 1);
			}

			//check down
			if (x < n - 1 && pipe[p][2] && pipe[map[x + 1][y]][0] && visited[x + 1][y] == 0) {

				visited[x + 1][y] = vis + 1;
				wh_x.push(x + 1);
				wh_y.push(y);
			}

			//check left
			if (y > 0 && pipe[p][3] && pipe[map[x][y - 1]][1] && visited[x][y - 1] == 0) {

				visited[x][y - 1] = vis + 1;
				wh_x.push(x);
				wh_y.push(y - 1);
			}

		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] <= l && visited[i][j] > 0) {
					space++;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", visited[i][j]);
			}
			printf("\n");
		}


		printf("#%d %d\n", tc, space);


	}

}