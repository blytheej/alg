#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	int arr[10003];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	bool first = true;

	for (int i = 0; i < n; i++) {
		if (arr[i] != i + 1) {
			first = false;
		}
	}

	if (first) {
		printf("-1");
		return 0;
	}

	prev_permutation(arr, arr+n);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}