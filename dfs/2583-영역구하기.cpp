#include <stdio.h>
#include <stdlib.h>

int m = 0, n = 0, k = 0; //세로 가로 input
int paper[101][101] = { 0, };
int areas = 0;
int area[10001];
int now = 0;


//dfs 이용
int check_area(int x, int y) {
	now++;
	if (x > 0 && paper[x - 1][y] == 0) {
		paper[x - 1][y] = 1;
		check_area(x - 1, y);
	}
	if (x + 1 < m && paper[x + 1][y] == 0) {
		paper[x + 1][y] = 1;
		check_area(x + 1, y);
	}
	if (y > 0 && paper[x][y - 1] == 0) {
		paper[x][y - 1] = 1;
		check_area(x, y - 1);
	}
	if (y + 1 < n && paper[x][y + 1] == 0) {
		paper[x][y + 1] = 1;
		check_area(x, y + 1);
	}

	return 0;
}

int comp(const void *a, const void *b)   
{
	int num1 = *(int *)a;    
	int num2 = *(int *)b;   

	if (num1 < num2)    
		return -1;     

	if (num1 > num2)   
		return 1;      

	return 0;    
}


int main() {
	
	scanf("%d %d %d", &m, &n, &k);


	while (k--) {
		int sx, sy, ex, ey;
		scanf("%d %d %d %d", &sy, &sx, &ey, &ex);

		for (int i = sx; i < ex; i++) {
			for (int j = sy; j < ey; j++) {
				paper[i][j] = -1;
			}
		}
	}
	
	//dfs 돌기
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i][j] == 0) {
				paper[i][j] = 1;
				check_area(i, j);
				area[areas] = now;
				areas++;
				now = 0;
			}
			
		}
	}
	
	qsort(area, sizeof(area) / sizeof(int), sizeof(int), comp);


	printf("%d\n", areas);
	for (int i = 10001-areas; i < 10001; i++){
		printf("%d ", area[i]);
	}

	return 0;
}