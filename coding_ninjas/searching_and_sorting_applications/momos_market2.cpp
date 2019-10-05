#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bs(ll* a, ll n, ll ele) {
    ll startp = 0;
    ll endp = n-1;
    ll midp;
    while(startp <= endp) {
        midp = (endp + startp)/2;
        if(a[midp] == ele) return midp;
        if(ele > a[midp]){
            startp = midp + 1;
        }else{
            if(midp - 1 <= 0) return 0;
            if(ele >= a[midp - 1]){
                 cout << "return: " << midp -1 ;
                 return midp - 1;
            } 
            endp = midp - 1;
        }
    }
    return -1;
}

int main(){
    ll n; cin >> n;
    ll* a = new ll[n]; for(ll i=0; i<n; i++) cin >> a[i];
    ll q; cin >> q;
    ll* x = new ll[q]; for(ll i=0; i<q; i++) cin >> x[i];
    
    ll* psa = new ll[n]; //prefix sum array
    psa[0] = a[0];
    for(ll i=1; i<n; i++) psa[i] = a[i] + psa[i-1];

    for(ll i=0; i<q; i++) {
        ll index = bs(psa, n, x[i]);
        cout << index + 1 << " " << x[i] - psa[index] << endl;
    }

    return 0;
}