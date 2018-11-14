#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll digital_root(ll n){
    if(n==0) return 0;
    return (n%9 == 0)? 9: n%9;
}

ll get_sum_from_front(ll a[], ll N, ll K){
    ll sum = 0;
    for(ll i=0; i<K; i++){
        sum += a[i];
    }
    return sum;
}

ll get_sum_from_back(ll a[], ll N, ll K){
    ll sum = 0;
    for(ll i=N-1; i>=N-K; i--){
        sum += a[i];
    }
    return sum;
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    ll a[N];
    for(ll i=0; i<N; i++){
        cin >> a[i];
        a[i] = digital_root(a[i]);
    }
    
    sort(a, a+N);
    for(ll i=0; i<Q; i++){
        ll type, K;
        cin >> type >> K;
        if(type == 1){ //max
            cout<< get_sum_from_back(a, N, K) << endl;
        }else{ //min
            cout<< get_sum_from_front(a, N, K) << endl;
        }
    }
    
    return 0;
}