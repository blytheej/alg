#include <stdio.h>
#include <string.h>

int main() {

	char name[10];
	bool fbi = false;

	for (int i = 0; i < 5; i++) {
		scanf("%s", &name);
		if (strstr(name, "FBI")) {
			printf("%d ", i + 1);
			fbi = true;
		}
	}
	if (!fbi) {
		printf("%s", "HE GOT AWAY!");
	}
}