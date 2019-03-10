#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int a[1<<24];
int dep, dat;
int n, l;

int get_min(int idx) {

	int mi = 1000000003;

	int s, e;
	if (idx - l + 1 <= 0) s = dat;
	else s = idx - l + dat + 1;
	e = idx + dat;

	while (s <= e) {
		if (s % 2 == 1) {
			if (mi > a[s]) {
				mi = a[s];
			}
			s++;
		}
		if (e % 2 == 0) {
			if (mi > a[e]) {
				mi = a[e];
			}
			e--;
		}
		s /= 2; e /= 2;
	}

	return mi;
}


int main() {
	
	scanf("%d %d", &n, &l);

	dep = (int)log2(n - 1) + 1;
	dat = pow(2, dep);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[dat + i]);
	}
	for (int i = dat - 1; i >= 0; i--) {
		a[i] = min(a[2 * i], a[2 * i + 1]);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ",get_min(i));
	}


}