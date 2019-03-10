#include <stdio.h>
#include <vector>
using namespace std;
int main() {

	long long int fac[23];

	fac[1] = 1;
	fac[0] = 1;
	for (int i = 2; i <= 20; i++) {
		fac[i] = fac[i - 1] * i;
	}

	int n, prob;
	scanf("%d %d", &n, &prob);
	vector<int> num;

	if (prob == 1) {
		for (int i = 1; i <= n; i++) {
			num.push_back(i);
		}

		long long int k;
		scanf("%lld", &k);
		k--;
		long long int t;
		for (int i = n - 1; i > 0; i--) {

			t = k / fac[i];
			printf("%d ", num[t]);
			num.erase(num.begin() + t);
			k = k % fac[i];
		}
		printf("%d", num[0]);
		return 0;
	}

	int d;
	int cnt[23];
	for (int i = 1; i <= n; i++) {
		cnt[i] = i;
	}
	long long int order = 0;
	for (int i = n - 1; i > 0; i--) {
		scanf("%d", &d);

		order += (cnt[d] - 1) * fac[i];
		for (int j = d; j <= n; j++) {
			cnt[j]--;
		}
	}
	printf("%lld", order + 1);



}