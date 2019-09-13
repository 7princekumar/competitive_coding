#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define int long long

int max(int a, int b){
	return (a > b) ? a : b;
}

int kadane(vector<int>& a, int n){
	int cs = 0, bs = INT_MIN; //curr_sum, best_sum
	for(int i=0; i<n; i++) {
		cs += a[i];
		bs = max(cs, bs);
		cs = max(cs, 0);
	}
	return bs;
}

int suffix_max_sum(vector<int>& a, int n){ 
	int cs = 0, bs = INT_MIN;
	for(int i=n-1; i>=0; i--) {
		cs += a[i];
		bs = max(cs, bs);
	}
	return bs;
}

int prefix_max_sum(vector<int>& a, int n){
	int cs = 0, bs = INT_MIN;
	for(int i=0; i<n; i++) {
		cs += a[i];
		bs = max(cs, bs);
	}
	return bs;
}

int full_sum(vector<int>& a, int n) {
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += a[i];
	}
	return max(sum, 0);
}

#undef int
int main() {
#define int long long
	int tc; cin >> tc; 
	while(tc--) {
		int n, k;
		cin >> n >> k;
		//int* a = new int[n];
		vector<int> a;
		int ele;
		for(int i=0; i<n; i++) {
			cin >> ele;
			a.push_back(ele);
		}
		int kr = kadane(a, n); //kadane's result
		int sms, pms, fs;      //suffix-max-sum, prefix-max-sum, full-sum
		if(k == 1) cout << kr << endl;
		else {
			sms = suffix_max_sum(a, n);
			pms = prefix_max_sum(a, n);
			fs  = full_sum(a, n);
			cout << max(kr, sms + (k-2)*fs + pms) << endl;
		}
	}
	return 0;
}