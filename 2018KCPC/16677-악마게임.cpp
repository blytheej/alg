#include <stdio.h>
#include <string.h>

char jam[102];
int jaml;

bool check(char cmp[102], int len) {

	int i = 0;
	int j = 0;
	
	bool a = true;

	while (true) {


		if (i < jaml && j == len) {
			a = false;
			break;
		}
		else if (i == jaml) {
			break;
		}

		if (jam[i] == cmp[j]) {
			i++; j++;
		}
		else {
			j++;
		}
	
	}	


	return a;
}

int main() {
	
	scanf("%s", &jam);
	jaml = strlen(jam);

	int n;
	scanf("%d", &n);
	
	char yjam[102];

	float jj = 0;
	char word[102];

	for (int i = 0; i < n; i++) {
		int cost;
		scanf("%s %d", &yjam, &cost);
		int yjaml = strlen(yjam);

		if ( yjaml > jaml && check(yjam, yjaml) && jj < (float)cost / (yjaml - jaml) ){
			jj = (float)cost / (yjaml - jaml);
			strcpy(word, yjam);
		}
	}

	if (jj == 0) {
		printf("No Jam");
	}
	else {
		printf("%s", word);
	}

}