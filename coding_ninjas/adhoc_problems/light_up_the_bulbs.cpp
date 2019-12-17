#include<bits/stdc++.h>
using namespace std;

int main() {
    #define int long
    int n, X, Y;
    string s; 
    cin >> n >> X >> Y;
    cin >> s;
    
    int groups = 0; //count of groups
    int i=0;
    if(s[0] == '0') {
        i++;
        groups++;
    }
    for(; i<s.length(); i++) {
        if(i+1 < s.length() && s[i]=='1' && s[i+1]=='0') groups++;
    }
    int ans = (groups == 0) ? 0 : ((groups -1) * min(X,Y)) + Y;
    cout << ans << endl;
	return 0;
}
