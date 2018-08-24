#include <stdio.h>
#include <string.h>

int main() {

	char a[100] = "whereisstring";
	char b[100] = "string";

	char *s3;
	s3 = strstr(a, b);

	printf("%s", s3);
}