#include <stdio.h>

int n, m;
int arr[502][502];
int max_point = 0;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

void tet(int x, int y, int v[502][502] , int sco, int len ) {

	if (len == 4) {
		max_point = max(sco, max_point);
		return;
	}
	//up
	if (x - 1 > -1 && !v[x - 1][y]) {
		v[x - 1][y] = 1;
 		tet(x - 1, y, v, sco + arr[x - 1][y], len + 1);
		v[x - 1][y] = 0;
	}
	//down
	if (x + 1 < n && !v[x + 1][y]) {
		v[x + 1][y] = 1;
		tet(x + 1, y, v, sco + arr[x + 1][y], len + 1);
		v[x + 1][y] = 0;
	}
	//left
	if (y - 1 > -1 && !v[x][y - 1]) {
		v[x][y - 1] = 1;
		tet(x, y - 1, v, sco + arr[x][y - 1], len + 1);
		v[x][y - 1] =0;
	}
	//right
	if (y +1 < m && !v[x][y + 1]) {
		v[x][y + 1] = 1;
		tet(x, y + 1,v, sco + arr[x][y + 1], len + 1);
		v[x][y + 1] = 0;
	}


}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i< n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	int v[502][502] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tet(i,j,v, 0, 0);
		}
	}
	int sco ;
	int mp =0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			sco = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
			mp = max(mp, sco);
			sco = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			mp = max(mp, sco);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			sco = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
			mp = max(mp, sco);
			sco = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			mp = max(mp, sco);
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			sco = arr[i][j] + arr[i +1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
			mp = max(mp, sco);
			sco = arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			mp = max(mp, sco);
		}
	}
	
	max_point = max(mp, max_point);

	printf("%d", max_point);
}