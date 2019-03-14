#include <stdio.h>
#include <vector>
using namespace std;

int area[60][60];
int w,h;
vector<int> x;
vector<int> y;



bool bfs() {


}


int main() {




	while (true) {


		scanf("%d %d", &w, &h);


		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {

				scanf("%d %d", &area[i][j]);

			}
		}
		int land = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (area[i][j] == 1) {
					area[i][j] = 0;
					land++;

					x.push_back(i);
					y.push_back(j);

					while (!x.empty()) {
						bfs();
					}
				}
			}
		}




	}


}