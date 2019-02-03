#include <iostream>
#define int long long
using namespace std;
int sqrt_n;

bool is_prime(int n){
	if(n < 2) return false;
	if(n == 2 || n==3) return true;
	if(n%2==0 || n%3==0) return false;
	for(int i=5; i*i<=n; i+=6){
		if(n%i == 0 || n%(i+2) == 0) return false;
	}
	return true;
}

#undef int
int main(){
#define int long long
	int t; cin >> t;
	while(t--){
		int a, b; cin >> a >> b;
		for(int i=a; i<=b; i++){
			if(is_prime(i)){
				cout << i << endl;
			}
		}
		cout << endl;
	}
	return 0;
}