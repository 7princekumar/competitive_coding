#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(ll* a, ll startp, ll midp, ll endp) {
    ll* merged = new ll[endp - startp + 1];
    ll i = startp;
    ll j = midp + 1;
    ll k = 0;
    ll ans = 0;
    while(i <= midp && j <= endp){
        if(a[i] < a[j]){
            ans += ((endp - j + 1) * a[i]);
            merged[k++] = a[i++];
        }else{
            merged[k++] = a[j++];
        }
    }
    while(i <= midp) merged[k++] = a[i++];
    while(j <= endp) merged[k++] = a[j++];
    k = 0;
    while(startp <= endp) a[startp++] = merged[k++]; //<= is very imp

    delete[] merged;
    merged = NULL;
    return ans;
}

ll merge_sort(ll* a, ll startp, ll endp) {
    if(startp >= endp) return 0ll;
    ll midp = startp + (endp-startp)/2;
    ll ans1 = merge_sort(a, startp, midp);
    ll ans2 = merge_sort(a, midp +1, endp);
    ll fans = ans1 + ans2 + merge(a, startp, midp, endp); //final_ans
    return fans;
} 

int main() {
    int tc; cin >> tc;
    while(tc-- ) {
        ll n; cin >> n;
        ll* a = new ll[n];
        for(ll i=0; i<n; i++) cin >> a[i];
        cout << merge_sort(a, 0, n-1) << endl;

        delete[] a;
        a = NULL;
    } 

    return 0;
}