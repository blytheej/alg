#include <stdio.h>
#include <vector>
using namespace std;

int n, k;
int map[10][10];
vector<int> topx;
vector<int> topy;
int maxh = 0; 
int maxl = 0;
int px[4] = { 0,0,-1,1 };
int py[4] = { -1, 1,0 ,0 };

int max(int a, int b) {
	return a > b ? a : b;
}

void route(int map[10][10], int x, int y, int len, bool candig, bool v[10][10]) {
	len++;
	maxl = max(len, maxl);

	int h;
	
	h= map[x][y];

	//printf("x: %d y:  %d len: %d h: %d \n", x, y, len,h);

	
	int cx, cy;
	int temp;
	for (int i = 0; i < 4; i++) {
		//in range
		cx = x + px[i];
		cy = y + py[i];
		if ( cx>= 0 &&cx < n && cy >= 0 && cy < n && !v[cx][cy]) {
			if (map[cx][cy] < h) {
				v[cx][cy] = true;
				route(map,cx, cy, len,candig,v);
				v[cx][cy] = false;
			}
			//can dig
			else if (candig && map[cx][cy] - k < h) {
				temp = map[cx][cy];
				map[cx][cy] = h - 1;
				v[cx][cy] = true;
				route(map,cx, cy, len, false,v); 
				map[cx][cy] = temp;
				v[cx][cy] = false;
			}
		}
	}
}



int main() {
	int test;
	//reset
	

	scanf("%d", &test);
	bool visited[10][10];
	for (int tc = 1; tc <= test; tc++) {
		maxl = 0; maxh = 0; topx.clear(); topy.clear();

		scanf("%d %d", &n, &k);

		//input
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				maxh = max(maxh, map[i][j]);
				visited[i][j] = false;
			}
		}
		//get start x y
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maxh == map[i][j]) {
					topx.push_back(i);
					topy.push_back(j);
				}
			}
		}
		
		for (int i = 0; i < topx.size(); i++) {
			//printf("%d!!!!!", i);
			visited[topx[i]][topy[i]] = true;
			route(map,topx[i], topy[i], 0, true, visited);
			visited[topx[i]][topy[i]] = false;
		}
		printf("#%d %d\n", tc, maxl);

	}
	
}