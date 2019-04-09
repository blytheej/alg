#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int test;
int n, k,l;
int pass[60] = { 0, };
vector<int> pw;

bool great(int a, int b) {
	return a > b;
}

int todec(int pas[10]) {

	int dec = 0;

	for (int i = 0; i < l;i++) {
		dec += pas[i] * pow(16, l-i-1);
	}
	return dec;
}

int main() {

	

	
	scanf("%d", &test);

	for (int tc = 1; tc <= test; tc++) {

		pw.clear();

		scanf("%d %d", &n, &k);
		l = n / 4;

		char hex;

		for (int i = 0; i < n; i++) {
			scanf(" %c", &hex);
			if (hex >= '0' && hex <= '9') {
				pass[i] = hex - '0';
				pass[n + i] = pass[i];
			}
			else {
				pass[i] = hex - 'A' + 10;
				pass[n + i] = pass[i];
			}
			
		}
		
		

		int check[10];
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < l; j++) {
				check[j] = pass[i + j];
			}
			pw.push_back(todec(check));
			
		}
	
		sort(pw.begin(), pw.end(),great);


		
	

		if (k == 1) {
			printf("#%d %d\n",tc, pw[0]);
			continue;
		}
		int kth = 1;
		for (int i = 1; i < n; i++) {
			if (pw[i - 1] != pw[i]) {
				kth++;
			 }
			if (kth == k) {
				printf("#%d %d\n",tc, pw[i]);
				break;
			}
		}
	}

}