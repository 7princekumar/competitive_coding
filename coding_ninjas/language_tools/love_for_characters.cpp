#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    unordered_map<char, int> m;
    for(int i=0; i<n; i++) {
        if(s[i] == 'a' || s[i] == 's' || s[i] == 'p') {
            m[s[i]]++;
        }
    }
    cout << m['a'] << " " << m['s'] << " " << m['p'] << endl;
	return 0;
}
