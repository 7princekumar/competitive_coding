#include <iostream>
#include <cstdbool>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

bool compare(ll a, ll b) {
	return a > b;
}

int main() {
	int n, m; cin >> n >> m;
	ll* arr = new ll[n];
	for(ll i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n, compare);
	queue<ll> q;
	int count_m = 0;
	int start_p = 0;
	for(int i=0; i<m; i++) {
		int curr_m; cin >> curr_m;
		ll ans;
		while(count_m < curr_m){
			if(start_p < n && (q.empty()|| (arr[start_p] >= q.front())) ){
				ans = arr[start_p];
				start_p++;
			}else{
				ans = q.front();
				q.pop();
			}
			q.push(ans/2);
			count_m++;
		}
		cout << ans << endl;
	}

	delete[] arr;
	arr = NULL;
	return 0;
}