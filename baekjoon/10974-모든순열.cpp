#include <stdio.h>

int n;

void nums(int num[9], int v[9], int len) {

	if (len == n) {
		for (int i = 1; i <= n; i++) {
		printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	
	for (int i = 1; i <= n; i++) {

		if (!v[i]) {
			num[len+1] =i;
			v[i] = 1;
			nums( num, v,len+1 );
			v[i] = 0;
		}	
	}
	return;
}




int main() {

	scanf("%d", &n);

	int arr[9];
	int visit[9] = { 0, };

	nums(arr, visit, 0);


}