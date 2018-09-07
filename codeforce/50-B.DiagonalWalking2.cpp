#include <stdio.h>

long long int check_dig(long long int w, long long int h, long long int k) {
	long long int dig = 0;
	long long int move = k;
	long long int left = w;

	if (k < w) {
		return -1;
	}
	//dig h moves
	dig = h; move -= h;
	left -= h;

	//move w+1
	dig += left / 2 * 2;
	move -= left / 2 * 2;

	if (left % 2 == 0) {  //left = 0
		if (move % 2 == 0) {
			dig += move;
		}
		else {
			dig += move - 2;
		}
	}
	else {				//left = 1
		dig += move - 1;
	}
	//in destin now

	return dig;
}

int main() {
	int tc;
	scanf("%d", &tc);

	long long int m, n, k;
	long long int w, h;
	for (int t = 0; t < tc; t++) {
		
		scanf("%lld %lld %lld", &m, &n, &k);
		long long int diagonal;
		//w longer, h shorter
		if (m >= n) {
			diagonal = check_dig(m,n,k);
		}
		else {
			diagonal = check_dig(n, m, k);
		}
		
		printf("%lld\n", diagonal);
	}
	

}