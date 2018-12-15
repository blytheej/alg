#include <stdio.h>

bool rsp(char a, char b) {
	if (a == 'S' && b == 'R') {
		return true;
	}
	else if (a == 'R' && b == 'P') {
		return true;
	}
	else if (a == 'P' && b == 'S') {
		return true;
	}
	else {
		return false;
	}

}



int main() {

	char m[2];
	char t[2];

	scanf("%c %c %c %c", &m[0], &m[1], &t[0], &t[1]);


	if (m[0] != m[1] && t[0] != t[1]) {
		printf("?");
	}
	else if (m[0] == m[1] && m[1] == t[0] && t[0] == t[1]) {
		printf("?");
	}
	else if (m[0] == m[1] && ( rsp(m[0], t[0]) || rsp(m[0], t[1] ))) {
		printf("TK");
	}
	else if (t[0] == t[1] && (rsp(t[0], m[0]) || rsp(t[0], m[1]))) {
		printf("MS");
	}
	else {
		printf("?");
	}
}