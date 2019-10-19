#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {return a > b;}

int main() {
    int n; cin >> n;
    int a[1005];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n, compare);
    long ans = 0;
    for(int i=0; i<n; i++) {
        cout << a[i] << " -> " << a[i] << " * " << "2^"<< i << " = " << a[i] + pow(2, i) << endl;
        ans += a[i] * pow(2, i);
    }
    cout << ans << endl;
    return 0;
}

// 3      
// 1 3 2
// 3 -> 3 * 2^0 = 4
// 2 -> 2 * 2^1 = 4
// 1 -> 1 * 2^2 = 5
// 11