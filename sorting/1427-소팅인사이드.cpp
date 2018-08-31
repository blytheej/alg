#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <functional>
using namespace std;

int main() {
	
	int num[12];
	int len = 0;

	while (true) {
		char now;
		scanf("%c", &now);
		if (now == '\n') { break; }
		num[len] = (int)now - '0';
		len++;
	}

	sort(num, num + len, greater<int>());
	for (int i = 0; i < len; i++) {
		printf("%d", num[i]);
	}
}