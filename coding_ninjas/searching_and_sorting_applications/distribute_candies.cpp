#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max_element(ll* a, ll n) {
    int ans = a[0];
    for(ll i=1; i<n; i++) {
        if(ans < a[i]) ans = a[i];
    }
    return ans;
}

bool is_possible(ll* a, ll n, ll pans, ll k) { //pans => possible_ans
    ll count = 0;
    for(ll i=0; i<n && count <=k; i++) {
        count += a[i] / pans;
    }
    return (count >= k) ? true : false;
} 

ll bs(ll* a, ll n, ll starta, ll enda, ll k) {
    ll ans = 0;
    ll mida;
    while(starta <= enda) {
        mida = starta + (enda - starta)/2; //mid_ans
        if(is_possible(a, n, mida, k)){
            ans = mida;
            starta = mida + 1;
        }else{
            enda = mida - 1;
        }
    }
    return ans;
}

int main() {
    int tc; cin >> tc;
    while(tc-- ) {
        ll n, k; cin >> n >> k;
        ll* a = new ll[n];
        for(ll i=0; i<n; i++) {
            cin >> a[i];
        }
        //possible ans range 0, max(a[])
        ll starta = 1; //start_ans
        ll enda = max_element(a, n); //end_ans

        //do binary search between possible ans range
        cout <<  bs(a, n, starta, enda, k) << endl;
        

        delete[] a;
        a = NULL;
    }
}