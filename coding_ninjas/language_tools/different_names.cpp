#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    unordered_map<string, int> m;
    while(cin >> s){  //YES, POSSIBLE!
        m[s]++;
    }
    bool found = false;
    unordered_map<string, int>::iterator itr;
    for(itr=m.begin(); itr!=m.end(); itr++) {
        if(itr->second > 1){
            found = true;
            cout << itr->first <<" " << itr->second <<endl;
        }
    }
    if(!found) cout << -1 << endl;
	return 0;
}
