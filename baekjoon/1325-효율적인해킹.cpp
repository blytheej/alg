#include <stdio.h>
#include <vector>
using namespace std;

int n, m;
vector< vector<int> > hack(10002, vector<int>(0, 0));

int hackcom(int k) {
	vector<int> com(10, 0);
	com.push_back(k);

	vector<int> hacked(10002, 0);

	hacked[k] = 1;

	int num =0;
	while (!com.empty()) {
		int a = com.back();
		com.pop_back();
		for (int i = 0; i < hack[a].size(); i++) {
			int add =  hack[a][i];
			if (hacked[add] == 0) {
				hacked[add] = 1;
				num++;
				com.push_back(add);
			}
		}
	}

	return  num;
}

int main() {


	scanf("%d %d", &n, &m);

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		hack[b].push_back(a);
	}
	
	int max =0;
	vector <int> maxcom;

	for (int i = 1; i <= n; i++) {
	
		int num = hackcom(i);
		if (num == max) {
			max = num;
			maxcom.push_back(i);
		}
		else if (num > max) {
			maxcom.clear();
			maxcom.push_back(i);
			max = num;
		}

	}

	for (int i = 0; i < maxcom.size(); i++) {
		printf("%d ", maxcom[i]);
	}
}