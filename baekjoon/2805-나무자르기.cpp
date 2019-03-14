#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	int arr[1000002];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}


	sort(arr, arr + n);

	int s = 0;
	int l = arr[n-1];
	int max = 0;

	while ( s <= l) {
	
		int mid = (s + l) / 2;
		long long int h = 0;

		for (int i = n-1; i >= 0; i--) {
			if (arr[i] > mid) {
				h += arr[i] - mid;
			}
			if (h >= m) {
				break;
			}
		}
		
		if (h >= m) {
			max = mid;
			s = mid + 1;
		}
		else {
			l = mid - 1;
		}
	}
	printf("%d", max);

}
