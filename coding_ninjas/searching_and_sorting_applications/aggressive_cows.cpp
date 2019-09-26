#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool placing_possible(vector<ll>& stalls, ll gap, ll c) {
    bool possible = true;
    int ccp = 0; // curr_cow_pos
    c--; //cow0 at 0th position
    for(int i=1; i<stalls.size() && c; i++) {
        if(stalls[i] - stalls[ccp] >= gap) {
            ccp = i;
            c--;
        }
    }
    return (c == 0) ? true : false;
}

//binary search on gaps
int bs(vector<ll>& stalls, ll start_gap, ll end_gap, ll mid_gap, ll c) {
    if(start_gap > end_gap) return mid_gap;
    ll temp = (start_gap + end_gap) / 2;
    if(placing_possible(stalls, temp, c)){
        return bs(stalls, temp +1, end_gap, temp, c);
    }else{
        return bs(stalls, start_gap, temp -1, temp, c);
    }
}

int main() {
    int tc; cin >> tc; 
    while(tc--) {
        ll n, c; cin >> n >> c; //n stall, c cows
        vector<ll> stalls;
        ll ele;
        for(ll i=0; i<n; i++) {
            cin >> ele;
            stalls.push_back(ele);
        }
        sort(stalls.begin(), stalls.end());
        // 1 <= gap <= stalls[n-1] - stalls[0]
        ll mid_gap = (1 + (stalls[n-1] - stalls[0])) / 2;
        ll gap = bs(stalls, 1, stalls[n-1] - stalls[0], mid_gap, c);
        cout << gap << endl;
    }
    return 0;
}