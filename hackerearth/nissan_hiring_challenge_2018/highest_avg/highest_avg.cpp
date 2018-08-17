#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

void print_i_v(vector<ll> &v){
    for(ll j=0; j<v.size(); j++){
        cout<<v[j]<<"\n";
    }
}

int main(){
    int N, Q;
    cin >> N;
    
    vector<ll> elements;
    ll ele;
    for(ll i=0; i<N; i++){
        cin >> ele;
        elements.push_back(ele);
    }

    cin >> Q;
    vector<ll> K;
    for(ll i=0; i<Q; i++){
        cin >> ele;
        K.push_back(ele);
    }

    vector<ll> results; //q answers

    sort(elements.begin(), elements.end());  
    //for each new value of K
    for(ll t=0; t< Q; t++){
        ll k = K[t];
        ll i = 1;
        long double sum = 0;
        long double avg = 0;
        bool found = false;
        while(i <= N && !found){
            //get avg of first i elements
            sum += elements[i-1];
            avg = sum / i;
            if(avg >= k){
                found = true;
                results.push_back(i-1);
                break;
            }
            i++;
        }
        if(found == false){
            if(i == N+1) results.push_back(N);
            else results.push_back(0);
        }
    }

    print_i_v(results);

    return 0;
}