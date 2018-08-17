#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> elements;
    ll ele;
    for(ll i=0; i<N; i++){
        cin>> ele;
        elements.push_back(ele);
    }

    vector<ll> v;
    for(ll i= N-K+1; i<N; i++){
        v.push_back(elements[i]);
    }
    for(ll i=0; i<K; i++){
        v.push_back(elements[i]);
    }

    // now find max-contiguous sum of length K in vector v
    ll max_sum = 0, local_sum = 0;
    ll v_size = v.size();
    for(ll i=0; i<K; i++){
        local_sum += v[i];
    }
    max_sum = local_sum;

    ll i = K;
    while(i < v_size){
        local_sum = local_sum + v[i] - v[i-K];
        max_sum = max(max_sum, local_sum);
        i++;
    }

    cout<< max_sum;
    return 0;
}
