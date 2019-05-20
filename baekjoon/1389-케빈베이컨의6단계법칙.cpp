#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;


int n, m;
vector< vector<int>> I(103);

int kmin = 1000000;
int kper = 0;

int min(int a, int b) {
	return a < b ? a : b;
}

int bfs(int s) {

	int k[102] = { 0, };

	queue<int> q;
	q.push(s);
	k[s] = 1;

	while (!q.empty()) {
		int a = q.front(); q.pop(); 
		int t;
		for (int i = 0; i < I[a].size(); i++) {
			t = I[a][i];
			if (k[t] == 0) {
				q.push(t);
				k[t] = k[a] + 1;
			}
		}
	}


	int kevins = 0;
	for (int i = 1; i <= n; i++) {
		k[i]--;
		kevins += k[i];
	}
	return kevins;

}


int main() {


	scanf("%d %d", &n, &m);

	int a, b;

	for (int i = 0; i < m; i++) {

		scanf("%d %d", &a, &b);
		I[a].push_back(b);
		I[b].push_back(a);
		
	}


	for (int i = 1; i <=n; i++) {
		
		int k = bfs(i);
		if (kmin > k) {
			kper = i;
			kmin = k;
		}
	}

	printf("%d", kper);
}