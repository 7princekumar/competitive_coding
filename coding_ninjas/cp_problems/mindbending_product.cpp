// Build a product array such that it contains product of all other 
// elements except element at that position.
// Constraint: No use of 'division' operator && Space Complexity should be of O(1)
#include <iostream>
using namespace std;

void print(int* a, int n){
	for(int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// Time Complexity:  O(n)
// Space Complexity: O(1)
void solve(int* a, int n) {
	int* p = new int[n];
	int rp = 1;
	p[0] = 1;
	for(int i=1; i<n; i++) {
		p[i] = a[i-1] * p[i-1];
	}
	for(int i=n-2; i>=0; i--) {
		rp *= a[i+1];
		p[i] *= rp;
	}
	print(p, n);
	delete[] p;
	p = NULL;
}

int main(){
	int a[] = {2,1,4,3,2};
	int n = sizeof(a)/sizeof(a[0]);
	solve(a, n);
	return 0;
}