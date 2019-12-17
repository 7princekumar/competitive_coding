#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, p, ans; 
    cin >> t;
    while(t-- ) {
        cin >> i >> p;
        ans =  (((i+1) % 12 + p) % 12) - 1;
        if(ans == -1) ans = 11;
        cout << ans << endl;
    } 
    
	return 0;
}
