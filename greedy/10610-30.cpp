#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>

using namespace std;

int main() {

	char inp[100003];
	int num[100003];
	scanf("%[^\n]c", &inp);
	int len = strlen(inp);
	bool iszero = false;

	for (int i = 0; i < len; i++) {
		num[i] = (int)inp[i] - '0';
		if (num[i] == 0) iszero = true;
	}

	if (!iszero){ printf("-1"); return 0;
	}

	int sum = 0;  

	for (int i = 0; i < len; i++) {
		sum += num[i];
	}
	if (sum % 3 != 0) { printf("-1"); return 0; }



	std::sort(num, num+len, greater<int>());

	
	for (int i = 0; i < len ; i++) {
		printf("%d", num[i]);
	}


}