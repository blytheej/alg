#include <stdio.h>



int n = 1;
int nums[14];

int lotto(int now[6], int len, int last) { // now_pick, now_pick's length, last idx
	if (len == 6) {
		printf("%d %d %d %d %d %d\n", now[0], now[1], now[2], now[3], now[4], now[5]);
	}
	else {
		int left = n - len;
		for (int i = last + 1; i < n ; i++) {
			now[len] = nums[i];
			lotto(now, len + 1, i);
		}
	}
	return 0;
}

int main() {
	
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		//input
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
			
		for (int i = 0; i < n - 5; i++) {
			int start[6];
			start[0] = nums[i];
			lotto(start, 1, i);
		}
	
		printf("%s", "\n");
		//reset
		for (int i = 0; i < 14; i++) {
			nums[i] = 0;
		}
	}

}