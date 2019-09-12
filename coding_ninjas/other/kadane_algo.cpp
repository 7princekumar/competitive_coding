//Max sum of contiguous subset
#include <iostream>
#include <algorithm>
using namespace std;

int kadane(int* a, int n){
	int curr_sum = 0;
	int best_sum = 0;
	for(int i=0; i<n; i++) {
		curr_sum += a[i];
		best_sum = max(curr_sum, best_sum);
		curr_sum = max(curr_sum, 0);
	}
	return best_sum;
}

int main(){
	int a[] = {-6,3,5,-20,1,7,1,-5,2,2,4,-2,1}; 
	int n = sizeof(a)/sizeof(a[0]);
	cout << kadane(a, n) << endl; //ans sum[1,7,1,-5,2,2,4] = 12
	return 0;
}