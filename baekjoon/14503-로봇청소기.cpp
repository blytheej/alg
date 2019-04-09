#include <stdio.h>

int clean_space = 1;
int ro[52][52];//room
bool cleaning = true;
int n, m, r, c, d;

int turn_left() {

	if (d == 0) {
		d =3;
	}
	else {
		d--;
	}
	return d;

}

bool check() {
	if (d == 0 && ro[r - 1][c] == 0) {
		r--;
		return true;
	}
	else if (d == 1 && ro[r][c + 1] == 0) {
		c++;
		return true;
	}
	else if (d == 2 && ro[r + 1][c] == 0) {
		r++;
		return true;
	}
	else if (d == 3 && ro[r][c - 1] == 0) {
		c--;
		return true;
	}
	else {
		return false;
	}

}


void clean() {


	int rotate = 0;
	// 2-1 & 2-2
	while (rotate < 4) {
		turn_left();
		
		if (check()) {
			clean_space++;
			ro[r][c] = 2;
			return;
		}
		
		rotate++;
	}
	
	if (d == 0) {
		if (ro[r + 1][c] == 1) {
			cleaning = false;
			return;
		}
		else {
			r++;
		}
	}
	if (d == 1) {
		if (ro[r][c - 1] == 1) {
			cleaning = false;
			return;
		}
		else {
			c--;
		}
	}
	if (d == 2) {
		if (ro[r - 1][c] == 1) {
			cleaning = false;
			return;
		}
		else {
			r--;
		}
	}
	if (d == 3) {
		if (ro[r][c + 1] == 1) {
			cleaning = false;
			return;
		}
		else {
			c++;
		}
	}



}


int main() {

	
	scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ro[i][j]);
		}
	}
	ro[r][c] = 2;
	while (cleaning) {

		clean();
	}

	printf("%d", clean_space);
}