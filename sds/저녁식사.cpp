#include <stdio.h>
#include <algorithm>
using namespace std;

struct wh {
	int x;
	int y;
	int idx;
};

bool cmp(wh a, wh b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}else return a.x < b.x;
}


int main() {


	int tc;
	scanf("%d", &tc);

	for (int test = 1; test <= tc; test++) {

		wh pl[200002];

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &pl[i].x, &pl[i].y);
			pl[i].idx = i+1;
		}

		sort(pl, pl + n, cmp);
		
		int min = 1000000002;

		printf("#%d", test);
		for (int i = 0; i < n; i++) {
			if (pl[i].y < min) {
				min = pl[i].y;
				printf(" %d", pl[i].idx);
			}

		}
		printf("\n");
	
	}


	




}