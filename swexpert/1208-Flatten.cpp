#include <stdio.h>






int main() {
	 

	for (int test = 1; test <= 10; test++) {

		int dump;
		scanf("%d", &dump);
		int h[102];
		for (int i = 0; i < 100; i++) {
			scanf("%d", &h[i]);
		}

		int diff;

		for (int d = 0; d < dump; d++) {

			int max = 0;
			int min = 102;
			int maxidx, minidx;

			for (int i = 0; i < 100; i++) {
				if (h[i] > max) {
					max = h[i];
					maxidx = i;
				}
				if (h[i] < min) {
					min = h[i];
					minidx = i;
				}
			}

			h[maxidx]--;
			h[minidx]++;
			
		}

		int max = 0;
		int min = 102;

		for (int i = 0; i < 100; i++) {
			if (h[i] > max) {
				max = h[i];
			}
			if (h[i] < min) {
				min = h[i];
			}
		}



		printf("#%d %d\n", test, max-min);
	}

}