#include <stdio.h>
#include <algorithm>
using namespace std;

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}


int main() {

	int n;
	scanf("%d", &n);
	int num[10003];

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	int ch;
	int idx;
	int nxt = 10003;
	int nidx;
	bool change = false;
	for (int i = n; i >= 2; i--) {
		if (num[i] > num[i - 1]) {
			idx = i - 1;
			ch = num[i - 1];

			for (int j = i; j <= n; j++) {
				if (num[j] > ch && num[j] < nxt) {
					nxt = num[j];
					nidx = j;
				}
			}
			
			num[idx] = nxt;
			num[nidx] = ch;
		

			sort(&num[i], &num[n+1]);
			
			change = true;
			break;
		}
	}
	if (!change) {
		printf("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", num[i]);
	}

}