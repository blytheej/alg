#include <stdio.h>
#include <queue>
using namespace std;

int visited[1002] = { 0, };
queue <int> visit;
int n, m, k, s;
int way[1002][1002] = { 0, };
int vil[11];
int min_sum;

void clear() {
	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 1002; j++) {
				way[i][j] = 0;
		}
	}
	for (int i = 0; i < 11; i++) {
		vil[i] = 0;
	}
	min_sum = 20000;
}

void clear_visited() {
	for (int i = 0; i < 11; i++) {
		visited[i] = 0;
	}
}


void bfs(int vil) {
	int now = visit.front();
	visit.pop();

	for (int i = 1; i <= n; i++) {
		if (way[vil][i] == 0 && way[now][i] == 1 && vil != i) {
			way[vil][i] = way[vil][now] + 1;
			visit.push(i);
		}
	}
	return;
}

void bt(int visited[1002], int sum,int last, int len) {


	if (len == k) { // 종료
		sum += way[last][s];
		if (min_sum > sum) {
			min_sum = sum;
		}
		return;
	}

	for (int i = 0; i < k; i++) {
		if (visited[vil[i]] == 0) {
			visited[vil[i]] = 1;
			bt(visited, sum + way[last][vil[i]], vil[i], len + 1);
			visited[vil[i]] = 0;
		}
	}

}

int main() {

	int tc;
	scanf("%d", &tc);
	for (int test = 1; test <= tc; test++) {
		//입력
		clear();

		scanf("%d %d %d %d", &n, &m, &k, &s);

		for (int i = 0; i < k; i++) {
			scanf("%d", &vil[i]);
		}
		int a, b;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			way[a][b] = 1;
			way[b][a] = 1;
		}
	
		//bfs로 거리찾기
		
		for (int i = 1; i <= n; i++) {
			if (way[s][i] == 1) {
				visit.push(i);
			}
		}
		while (!visit.empty()) {
			bfs(s);
		}

		for (int i = 0; i < k; i++) {
			clear_visited();
			for (int l = 1; l <= n; l++) {
				if (way[vil[i]][l] == 1) {
					visit.push(l);
				}
			}
			while (!visit.empty()) {
				bfs(vil[i]);
			}
		}
		
		 
		//n! 번 돌리면서 최단 싸이클 찾기 backtracking
		clear_visited();

		for (int i = 0; i < k; i++) {
			int sum = way[s][vil[i]];
			visited[vil[i]] = 1;
			bt(visited, sum, vil[i], 1);
			visited[vil[i]] = 0;
		}

		printf("#%d %d\n",test, min_sum);

	}


}