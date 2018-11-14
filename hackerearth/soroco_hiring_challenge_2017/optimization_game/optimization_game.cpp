#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    ll T; cin>> T;
    while(T--){
        ll N; cin>> N;
        ll v[100210] = {0};
        for(ll i=0; i<N; i++){
            cin >> v[i];
        }
        
        ll ans = 0;
        for(ll i=0; i<100010 + 200; i++){
            v[i+1] += v[i]/2;
            v[i] %= 2;
            ans += v[i];
        }
        cout<< ans << endl;
        
    }
    return 0;
}