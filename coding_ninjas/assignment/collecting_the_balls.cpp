#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll n, ll k) {
    ll n_copy = n;
    ll sum = 0;
    while(n > 0) {
        sum += min(k, n);
        n -= k;
        n -= n/10;
    }
    return (2 * sum >= n_copy) ? true : false;
}

void bs(ll n, ll startp, ll endp, ll* ans) {
    ll midp;
    while(startp <= endp){
        midp = startp + (endp - startp)/2;
        if(check(n, midp)){
            *ans = midp;
            endp = midp -1;
        }else{
            startp = midp +1;
        }
    }
}

void solve(ll n) {
    ll ans = 1;
    bs(n, 1,n, &ans);
    cout << ans << endl;
}


int main(){
    ll n; cin >> n;
    solve(n);
	return 0;
}
