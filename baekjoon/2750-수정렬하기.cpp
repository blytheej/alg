#include <stdio.h>
#include <algorithm>


int main() {


	int n;
	scanf("%d", &n);
	int arr[1000002];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	std::sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}