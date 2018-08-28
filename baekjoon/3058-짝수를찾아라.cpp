#include <stdio.h>




int main() {
	
	int tc = 0;
	scanf("%d", &tc);



	while (tc--) {

		int sum = 0;
		int smallest = 102;
		int now = 0;
		for (int i = 0; i < 7; i++) {
			scanf("%d", &now);
			
			if (now % 2 == 0) {
				if (now < smallest) smallest = now;
				sum += now;
			}
		}
		printf("%d %d\n", sum, smallest);


	}

}