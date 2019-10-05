#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(){
    ll n; cin >> n;
    ll* a = new ll[n]; for(ll i=0; i<n; i++) cin >> a[i];
    ll q; cin >> q;
    ll ele;
    pll* x = new pll[n]; 
    for(ll i=0; i<q; i++){
        cin >> x[i].first;
        x[i].second = i;
    }

    sort(x, x+q);
    ll pos = 0; //position ptr for a
    ll count = 0;
    ll money_spent = 0;
    pll* ans = new pll[q];
    for(ll i=0; i<q; i++) {
        ll money_left = x[i].first - money_spent;
        while(pos < n && money_left - a[pos] >= 0){
            count++;
            money_spent += a[pos];
            money_left -= a[pos];
            pos++;
        }
        ans[x[i].second].first = count;
        ans[x[i].second].second = money_left;
    }
    for(ll i=0; i<q; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    delete[] a; delete[] x; delete[] ans;
    a = NULL;
    x = ans = NULL;
    return 0;
}