#include <stdio.h>
#include <algorithm>
using namespace std;


int main() {

	int n;
	scanf("%d", &n);

	int a, b, c;
	int mna=0, mnb=0, mnc = 0;
	int mxa=0, mxb=0, mxc =0 ;

	int x1, x2, x3;
	int n1, n2, n3;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);

		n1 = a + min(mna, mnb);
		n2 = b + min(mna, min(mnb, mnc));
		n3 = c + min(mnb, mnc);

		x1 = a + max(mxa, mxb);
		x2 = b + max(mxa, max(mxb, mxc));
		x3 = c + max(mxb, mxc);

		mna = n1; mnb = n2; mnc = n3;
		mxa = x1; mxb = x2; mxc = x3;
	}


	int mn, mx;
	mn = min(mna, min(mnb, mnc));
	mx = max(mxa, max(mxb, mxc));

	printf("%d %d", mx, mn);
}