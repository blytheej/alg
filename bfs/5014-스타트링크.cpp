#include <stdio.h>
#include <queue>

std::queue<int> gofloor;
int f, s, g, u, d; // highest, start, finish, up, down
int move;
int floors[1000004];

int und() { //up and down
	int  now = gofloor.front();
	gofloor.pop();

	if (now + u <= f && floors[now + u] == 0) {
		floors[now + u] = floors[now] + 1;
		gofloor.push(now + u);
	}
	if (now - d > 0 && floors[now - d] == 0) {
		floors[now - d] = floors[now] + 1;
		gofloor.push(now - d);
	}

	return 0;
}

int main() {

	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	if (s == g) {
		printf("0");
		return 0;
	}
	gofloor.push(s);
	floors[s] = 1;

	while (!gofloor.empty()) {
	und();
	}
	int finish = floors[g];
	if (finish > 0) {
		printf("%d", finish - 1);
	}
	else {
		printf("use the stairs");
	}
	

}