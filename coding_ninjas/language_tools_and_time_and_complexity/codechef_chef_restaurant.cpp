//https://www.codechef.com/problems/CHEFRES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll > vpll;

int main(){
    int tc; cin >> tc;
    while(tc-- ) {
        ll n, m; cin >> n >> m;
        vpll ti; //time_intervals
        ll l, r;
        while(n-- ) {
            cin >> l >> r;
            ti.push_back(make_pair(l, r));
        } 
        sort(ti.begin(), ti.end());
        ll pat; //person's arrival time
        
        while(m-- ){
            cin >> pat; 
            ll lbi = lower_bound(ti.begin(), ti.end(), make_pair(pat, 0ll)) - ti.begin(); //lbi => lb_index
            //if lbi is 0 [handle one more case when lbi is out of bound differently]
            if(lbi == 0) {
                cout << ti[0].first - pat << endl;
            }else{
                ll ans = -1;
                //if lbi is within array range
                //if lbi is btw pairs or matches lb's pair's arrival time only
                if((ti[lbi].first == pat) || (ti[lbi -1].second > pat)){
                    ans = 0;
                }else if(lbi < ti.size()){
                    ans = ti[lbi].first - pat;
                }
                //if ans = -1, it means, lb is out of bound
                cout << ans << endl;
            }   
        }
    }
    return 0;
}