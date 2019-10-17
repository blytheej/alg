#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

vector< vector<int> > nummin(10);
vector< vector<int> > nummax(10);

int cntmin[10] = { 0, };
int cntmax[10] = { 0, };
int mx[10];
int mn[10];
int n;
vector<int> stmin;
vector<int> stmax;


int main() {

	scanf("%d", &n);

	char c;

	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);

		if (c == '<') {
			cntmin[i]++;
			cntmax[i + 1]++;
			nummin[i + 1].push_back(i);
			nummax[i].push_back(i+1);
		}
		else {
			cntmin[i + 1]++;
			cntmax[i]++;
			nummin[i].push_back(i + 1);
			nummax[i + 1].push_back(i);
		}
	}

	int a =9 - n, b = n;

	for (int i = 0; i <= n; i++) {
		if (cntmin[i] == 0) {
			stmin.push_back(i);
		}
		if (cntmax[i] == 0) {
			stmax.push_back(i);
		}
	}

	int t;
	while (!stmin.empty()) {
		sort(stmin.begin(), stmin.end(), less<int>());

		t = stmin.back(); stmin.pop_back();
		cntmin[t] = -1;
		mn[t] = b; b--;
		
		for (int i = 0; i < nummin[t].size(); i++) {
			int k = nummin[t][i];
			cntmin[k]--;
			if (cntmin[k] == 0) {
				stmin.push_back(k);
			}
		}
	}

	while (!stmax.empty()) {
		sort(stmax.begin(), stmax.end(), less<int>());

		t = stmax.back(); stmax.pop_back();
		cntmax[t] = -1;
		mx[t] = a; a++;

		for (int i = 0; i < nummax[t].size(); i++) {
			int k = nummax[t][i];
			cntmax[k]--;
			if (cntmax[k] == 0) {
				stmax.push_back(k);
			}
		}
	}
	
	for (int i = 0; i <= n; i++) {
		printf("%d", mx[i]);
	}

	printf("\n");
	for (int i = 0; i <= n; i++) {
		printf("%d", mn[i]);
	}
}