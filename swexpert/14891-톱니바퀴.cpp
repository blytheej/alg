#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int saw[5][9];
int sidx[5];//saw's index

int get(int num, int wh) { // num : Åé´µ wh : 2 or 6
	int n = sidx[num];
	if (wh==2) {
		n += 2;
	}
	else {
		n += 6;
	}
	if (n > 8) {
		n -= 8;
	}

	return saw[num][n];
}

void turn(int num, int d) {
	if (d == 0) {
		return;
	}
	if (d == -1) {
		sidx[num]++;
		if (sidx[num] > 8) {
			sidx[num] -= 8;
		}
	}
	else {
		sidx[num]--;
		if (sidx[num] < 1) {
			sidx[num] += 8;
		}
	}
}

int main() {


	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			scanf("%1d", &saw[i][j]);
		}
		sidx[i] = 1;
	}
	
	int k;
	scanf("%d", &k);

	int num, d;
	int turnd[5] = { 0, };
	for (int ks = 0; ks< k; ks++) {
		scanf("%d %d", &num, &d);

		for (int i = 1; i <=4; i++) {
		turnd[i] = 0;
		}

		turnd[num] = d;
		
		// <<
		for (int i = num-1; i >= 1; i--) {
			if (get(i, 2) == get(i+1, 6)) {
				break;
			}
			turnd[i] = -turnd[i + 1];
		}

		//>>
		for (int i = num+1; i <= 4; i++) {
			if (get(i - 1, 2) == get(i, 6)) {
				break;
			}
			turnd[i] = -turnd[i - 1];
		}
		

		for (int i = 1; i <= 4; i++) {
			turn(i, turnd[i]);
		}

		
	}
	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		if (saw[i][sidx[i]] == 1) {
			sum += pow(2, i-1);
		}
	}

	printf("%d", sum);

}