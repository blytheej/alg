#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321

struct way {

	int ar, pr;

};

struct cmp {
	bool operator()(way a, way b){
	
		return a.pr > b.pr;
	}
};

vector< vector<way>> ed(1003);
priority_queue<way, vector<way>, cmp> q;
int prices[1003];


void dij() {

	way x;
	way y;
	while (!q.empty()) {
		
		x = q.top();
		q.pop();

		for (int i = 0; i < ed[x.ar].size(); i++) {
			y = ed[x.ar][i];
			if (prices[x.ar] +y.pr < prices[y.ar]) {
				prices[y.ar] = prices[x.ar] + y.pr;
				q.push({ y.ar, prices[y.ar] });
			}
		}
		ed[x.ar].clear();
	}


}

int main() {


	int n, m;
	scanf("%d %d", &n, &m);

	int a, b, c;
	for (int i = 0; i < m; i++) {

		scanf("%d %d %d", &a, &b, &c);

		ed[a].push_back({ b,c });

	}

	int start, end;
	scanf("%d %d", &start, &end);

	for (int i = 1; i <= n; i++) {
		prices[i] = INF;
	}
	prices[start] = 0;

	q.push({ start,0 });

	dij();


	printf("%d", prices[end]);
}

