#include <stdio.h>
#include <string.h>

int main() {

	int n, m, q;

	scanf("%d %d %d", &n, &m, &q );

	char a[1001];
	char b[1001];
	char total = 0;
;	if (n < m) {
		for (int i = 0; i < q; i++) {
			printf("%d\n", 0);
		}
	}

	else {
		scanf("%s %s", &a, &b);
		char times[1001] = { 0, };
			
		for (int i = 0; i < n - m + 1; i++) {
			bool contain = true;
			for (int j = 0; j < m; j++) {
				// i, i+1, i+2,   i+m-1 까지 비교
				if ( a[i + j] != b[j]) {
					contain = false;
				}
			}
			if (contain) {
				times[i] = 1;
				total++;
			}
		}
		if (total == 0) {
			for (int i = 0; i < q; i++) {
				printf("%d\n", 0);
			}
		}else{
			for (int i = 0; i < q; i++) {
				int start, end = 0;
				scanf("%d %d", &start, &end);
				start--; end--;
				int howmany = 0;
				for (int k = start; k <= end; k++) {
					if (times[k] == 1 && k + m - 1 <= end) {
						howmany++;
					}
				}
				printf("%d\n", howmany);
			}
		}
	}
	

}