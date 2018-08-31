#include <stdio.h>
#include <algorithm>
#include <string.h>


int main() {

	char words[20001][52];
	int len[20001][2]; // 0 : word length , 1: origin idx
	int n = 0;
	scanf("%d", &n);
	
	char now[52];
	for (int i = 0; i < n; i++) {
		scanf("%s", &words[i]);
		int lenn = strlen(words[i]);
		len[i][0] = lenn;
		len[i][1] = i;

	}

	
}