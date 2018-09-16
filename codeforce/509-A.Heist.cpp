#include <stdio.h>




int main() {

	int max = 0, min = 1000000001;
	int item;
	scanf("%d", &item);

	int num;
	for (int i = 0; i < item; i++) {
		scanf("%d", &num);
		if (num > max) { max = num; }
		if (num < min) { min = num; }
	}
	
	int stolen = max - min + 1;
	printf("%d", stolen - item);

}