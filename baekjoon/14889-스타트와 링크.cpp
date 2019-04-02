#include <stdio.h>

int N;
int n ;
int sco[20][20];
int min_sco = 30000;

int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}

int get_score(int sl[20]) {

	int start=0, link = 0; // start : 0  / link : 1

	for (int i = 0; i < N; i++) {
		if (sl[i] == 0) {
			for (int j = 0; j < N; j++) {
				if (sl[j] == 0) {
					start += sco[i][j];
				}
			}
		}
		if (sl[i] == 1) {
			for (int j = 0; j < N; j++) {
				if (sl[j] == 1) {
					link += sco[i][j];
				}
			}
		}
	}
	return max(start, link) - min(start, link);

}

void pick(int arr[20], int last, int len) {
	// n picked, get scores and compare
	if (len == n ) {
		for (int i = 0; i < N; i++) {
			//printf("%d ", arr[i]);
		}
		min_sco = min(min_sco, get_score(arr));
		return;
	}
	//can not pick n with remaining
	if (N - last <= n - len) {
		//printf("ºÎÁ· %d %d %d %d\n",N,last, n, len);
		return;
	}

	for (int i = last + 1; i < N; i++) {
		arr[i] = 1;
		pick(arr, i, len + 1);
		arr[i] = 0;
	}

}


int main() {

	scanf("%d", &N);
	n = N / 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &sco[i][j]);
		}
	}
	
	int p[20] = { 0, };

	for (int i = 0; i < n; i++) {
		p[i] = 1;
		pick(p, i, 1);
		p[i] = 0;
	}

	printf("%d", min_sco);

}