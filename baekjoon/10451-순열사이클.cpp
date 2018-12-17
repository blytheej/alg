#include <stdio.h>

int arr[1002];
bool done[1002];

void clear() {
	for (int i = 0; i < 1002; i++) {
		done[i] = false;
		arr[i] = 0;
	}
}

void cycle(int start) {

	int a = arr[start];

	if (done[a]) {
		return ;
	}
	else {
		done[a] = true;
		return cycle(a);
	}

}

int main() {

	int tc;

	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		clear();

		int n;
		scanf("%d", &n);
		int cycles =0; 

	
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			arr[i]--;
		}

		for (int i = 0; i < n; i++) {
			if (!done[i]) {
				cycles++;
				done[i] = true;
				cycle(i);
			}
		}
		printf("%d\n", cycles);	
	}

}