#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc; cin >> tc;
    while(tc--) {
        long long n; cin >> n;
        long long sum = 0;
        while(n){
            sum += n%10;
            n = n/10;
        }
        cout << sum << endl;
    }
    return 0;
}