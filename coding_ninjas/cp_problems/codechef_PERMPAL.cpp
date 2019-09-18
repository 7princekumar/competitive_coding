#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	while(n--) {
		string s; cin >> s;
		unordered_map<char, vector<int> > m;
		for(int i=0; i<s.length(); i++) {
			m[s[i]].push_back(i);
		}
		int odd_count = 0;
		for(char c = 'a'; c <= 'z'; c++) {
			if(m[c].size() == 0) continue;
			if(m[c].size() % 2 == 1) odd_count++;
		}
		if(odd_count > 1) {
			cout << -1 << endl;
		}else{
			vector<int> ans(s.length());
			int frontp = 0; 			// front_position
			int backp = s.length() - 1; // back_position
			for(char c = 'a'; c <= 'z'; c++) {
				if(m[c].size() == 0) continue;
				if(m[c].size() % 2 == 1){ //odd length case, only one will have odd freq
					ans[s.length() / 2] = m[c][0];
					for(int i=1; i<m[c].size() -1; i+=2) {
						ans[frontp++] = m[c][i];
						ans[backp--]  = m[c][i+1];
					}
				}else{
					for(int i=0; i<m[c].size() -1; i+=2) {
						ans[frontp++] = m[c][i];
						ans[backp--]  = m[c][i+1];
					}
				}
			}
			for(int i=0; i<s.length(); i++) {
				cout << ans[i] + 1<< " ";
			}
			cout << endl;
		}
	}
}