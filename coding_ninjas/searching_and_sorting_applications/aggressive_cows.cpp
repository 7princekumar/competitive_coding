#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_possible(vector<ll>& stalls, ll gap, ll c) {
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
int bs(vector<ll>& stalls, ll start, ll end, ll c) {
    ll ans = -1;
    ll mid;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(is_possible(stalls, mid, c)){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
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
        ll start = 0;
        ll end = stalls[n-1] - stalls[0];
        
        ll ans = bs(stalls, start, end, c);
        cout << ans << endl;
    }
    return 0;
}