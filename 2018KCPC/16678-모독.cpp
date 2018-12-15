#include <stdio.h>
#include<algorithm>


int main() {


	int n;
	scanf("%d", &n);

	long long int hack = 0;
	int num[100002];


	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	std::sort(num, num + n);

	int now = 1;


	for (int i = 0; i < n; i++) {
		if (num[i] >= now) {
			hack += num[i] - now;
			now++;
		}
	}

	printf("%lld", hack);

}