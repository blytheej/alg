#include <stdio.h>


int n = 0;

int small[80];
bool printed = false;

int good(int now[82], int idx) { // now's number, idx
	if (printed) return 0;
	int to = idx / 2 + 1;
	if (idx + 1 == n) {
		printed = true;
		for (int i = 0; i < idx + 1; i++) {
			printf("%d", now[i]);
		}
		printf("\n");
		return 0;
	}
	for (int add = 1; add <= 3; add++) { // new num add
		now[idx + 1] = add;
		bool isgood = true;

		for (int i = 0; i < to; i++) {
			bool same = true;
			for (int j = 0; j < i + 1; j++) {
				if (now[idx + 1 - j] != now[idx - i- j]) {
					same = false;
				}
				if (!same)  break;
			}
			if(same) isgood = false;
		}
		if (isgood) {
			good(now, idx + 1);
		}
	}
	return 0;
}

int main() {
	
	scanf("%d", &n);

	int nums[80];
	nums[0] = 1;

	good(nums, 0);

}