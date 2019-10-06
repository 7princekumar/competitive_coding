#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//solve: i + tn >= a[i]  -> solve for t
ll solve(ll i, ll n, ll ai) {
    if(ai - i <= 0) return 0;
    return ((ai - i)%n == 0) ? (ai -i)/n : (ai -i)/n + 1;
}

ll find_min_pos(ll* a, ll n) {
    ll min_ele_pos = 0;
    for(ll i=1; i<n; i++) {
        if(a[i] < a[min_ele_pos]) min_ele_pos = i;
    }
    return min_ele_pos;
}

void print(ll* a, ll n) {
    for(ll i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    ll n; cin >> n;
    ll* a = new ll[n];
    ll* t = new ll[n];
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) {
        t[i] = solve(i, n, a[i]);
    }
    //print(t, n);
    cout << find_min_pos(t, n) + 1 << endl;

    delete[] a; delete[] t;
    a = t = NULL;
	return 0;
}
