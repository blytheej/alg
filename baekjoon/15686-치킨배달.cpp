#include <stdio.h>
#include<vector>
using namespace std;

int n, m;
int map[52][52];

vector<int> hx;
vector<int> hy;
vector<int> cx;
vector<int> cy;
vector< vector<int>> cd(14);

int hl, cl;

int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}

int min_dist = 1000000;

void choose_c(int dist[102] ,int st, int len) {

	if (len == m || st == cl) {
		int dd = 0;
		for (int i = 0; i < hl; i++) {
			dd += dist[i];
		}
		min_dist = min(min_dist, dd);
		return ;
	}

	int odist[102];
	for (int i = 0; i < hl; i++) {
		odist[i] = dist[i];
	}

	for (int i = st; i < cl; i++) {

		for (int j = 0; j < hl; j++) {

			dist[j] = min(odist[j], cd[i][j]);

		}
		choose_c(dist, i+1, len + 1);

	}


}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				hx.push_back(i);
				hy.push_back(j);
			}
			if (map[i][j] == 2) {
				cx.push_back(i);
				cy.push_back(j);
			}
		}
	}
	hl = hx.size();
	cl = cx.size();


	//get every chick dist
	for (int i = 0; i<  cl; i++) {
		for (int j = 0; j < hl; j++) {
		cd[i].push_back(max(hx[j], cx[i]) + max(hy[j], cy[i]) - min(hx[j], cx[i]) - min(hy[j], cy[i])) ;
		}
	}


	int dist[102];
	for (int i = 0; i < hl; i++) {
		dist[i] = 200;
	}

	choose_c(dist, 0, 0);

	printf("%d", min_dist);

}