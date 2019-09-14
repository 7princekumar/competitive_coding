//max product of sub-array
#include<iostream>
using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int solve(int* a, int n) {
	int bpp = 1, bnp = 1; //best-positive-product, best-negative-product
	int cpp = 1, cnp = 1; //curr-positive-product, curr-negative-product
	// three cases
	for(int i=0; i<n; i++) {
		if(a[i] == 0) {
			cpp = cnp = 1;
		}else if(a[i] > 0) {
			cpp *= a[i];
			cnp *= a[i];
		}else {
			int temp_cnp = cnp;
			cnp = min(cnp, cpp * a[i]);
			cpp = max(cpp, temp_cnp * a[i]);
		}
		bpp = max(bpp, cpp);
		bnp = min(bnp, cnp);
	}
	return bpp;
}

int main() {
	int a[] = {6, -3, -10, 0, 2};
	int n = sizeof(a)/sizeof(a[0]);
	cout << solve(a, n) << endl;
 	return 0;
}