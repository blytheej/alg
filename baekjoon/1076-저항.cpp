#include <stdio.h>
#include <math.h>
#include  <string.h>

int color_check(char color[10]) {

	if (!strcmp(color,"black")) {
		return 0;
	}
	else if (!strcmp(color, "brown")) {
		return 1;
	}
	else if (!strcmp(color, "red")) {
		return 2;
	}
	else if (!strcmp(color, "orange")) {
		return 3;
	}
	else if (!strcmp(color, "yellow")) {
		return 4;
	}
	else if (!strcmp(color, "green")) {
		return 5;
	}
	else if (!strcmp(color, "blue") ){
		return 6;
	}
	else if (!strcmp(color, "violet")){
		return 7;
	}
	else if (!strcmp(color, "grey")) {
		return 8;
	}
	else if (!strcmp(color, "white") ){
		return 9;
	}
	return 0;
}

int main() {

	char fir_c[10];
	char sec_c[10];
	char thi_c[10];
	
	scanf("%s %s %s", &fir_c, &sec_c, &thi_c);
	int f = color_check(fir_c);
	int s = color_check(sec_c);
	int t = color_check(thi_c);
	
	if (f == 0 && s == 0) {
		printf("%d", 0);
	}
	else {
		if (f > 0) {
			printf("%d", f);
		}
		printf("%d", s);
		for (int i = 0; i < t; i++) {
			printf("%d", 0);
		}
	}
			
	
	return 0;
}