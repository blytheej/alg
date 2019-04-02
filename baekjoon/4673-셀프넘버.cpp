#include <stdio.h>

int  self[10003] = { 0, };

void d(int num) {

	int sum = num;

	while (num >0) {
		sum += num % 10;
		num /= 10;
	}
	self[sum] = 1;
	return ;
}


int main() {

	
	for (int i = 1; i <= 10000; i++) {
		if (self[i] == 0) {
			printf("%d\n", i);
		}
			d(i);	
	}
	
	

}