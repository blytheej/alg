#include <stdio.h>
#include <vector>
using namespace std;

int main() {

	int tc;
	scanf("%d", &tc);
	for (int test = 0; test < tc; test++) {
		

		vector <char> a;


		int len;
		scanf("%d", &len);

		char alp;
		scanf(" %c ", &alp);
		a.push_back(alp);

		for (int i = 1; i < len; i++) {

			char h = a.front();
			char now;
			scanf(" %c", &now);
			if (h <= now) {
				a.insert(a.begin(), now);
			}
			else {
				a.push_back(now);
			}
		}
		printf("#%d ", test + 1);
		for (int i = 0; i < len; i++) {
			printf("%c", a[i]);
		}

		printf("\n");
	}

}

