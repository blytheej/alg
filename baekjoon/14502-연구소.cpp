#include <stdio.h>
#include <vector>
#include<queue>
#include <algorithm>
using namespace std;

int n, m;
int lab[66][66];
vector<int> x;
vector<int> y;
vector<int> twox;
vector<int> twoy;
queue<int> bx;
queue<int> by;

int tlab[66][66];
int cx[4] = { 0, 0, 1, -1 };
int cy[4] = { 1, -1, 0, 0 };


int check(int a, int b, int c) {
	//test lab
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tlab[i][j] = lab[i][j];
		}
	}
	//set the wall
	tlab[x[a]][y[a]] = 1;
	tlab[x[b]][y[b]] = 1;
	tlab[x[c]][y[c]] = 1;

	//put virus in queue
	for (int i = 0; i < twox.size(); i++) {
		bx.push(twox[i]);
		by.push(twoy[i]);
	}

	//spread virus
	int vx, vy; // virus x y
	int tlabx, tlaby;
	while (!bx.empty()) {
		vx = bx.front(); bx.pop();
		vy = by.front(); by.pop();
		
		for (int i = 0; i < 4; i++) {
			tlabx = vx + cx[i];
			tlaby = vy + cy[i];
			if (tlabx >= 0 && tlabx < n && tlaby >= 0 && tlaby < m && !tlab[tlabx][tlaby]) {
				bx.push(tlabx);
				by.push(tlaby);
				tlab[tlabx][tlaby] = 2;
			}
		}
	}

	//check
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//printf("%d ", tlab[i][j]);
			if (tlab[i][j] == 0) {
				s++;
			}
		}
		//printf("\n");
	}
	//printf("\n");
	return s;

}


int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j]== 0) {
				x.push_back(i);
				y.push_back(j);
			}
			if (lab[i][j] == 2) {
				twox.push_back(i);
				twoy.push_back(j);
			}
		}
	}
	int v = x.size();
	int safe;
	int max_safe = 0;
	for (int i = 0; i < v; i++) {
		for (int j = i + 1; j < v; j++) {
			for (int k = j + 1; k < v; k++) {
				safe = check(i, j, k);
				max_safe = max(safe, max_safe);
			}
		}
	}
	 
	printf("%d", max_safe);
}