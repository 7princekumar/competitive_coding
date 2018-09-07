//still wrong
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map> //pairs
#include <unordered_set> //hash
#include <utility> //for pair, make_pair

using namespace std;
typedef long long ll;
const int N=1e5+5;

int main() {
    ll n;
    cin >> n;
    vector<ll> l1;
    l1.resize(N);
    vector<ll> l2;
    l2.resize(N);
    ll ele;
    for(ll i=0; i<n; i++){
        cin >> ele;
        l1.push_back(ele);
    }
    for(ll i=0; i<n; i++){
        cin >> ele;
        l2.push_back(ele);
    }

    sort(l1.rbegin(), l1.rend()); 
    sort(l2.rbegin(), l2.rend()); 
    ll sum1 = 0; int i =0;
    ll sum2 = 0; int j =0;
    int moves = 0;
    bool player1 = true;
    while(moves < 2*n){
        moves++;
        if(player1){
            if(l1[i] >= l2[j]){ //element left && own is greater, take it
                sum1 += l1[i];
                i++;
            }else{ //remove his
                j++;
            }
        }else{
            if(l2[j] >= l1[i]){ //own is greater, take it
                sum2 += l2[j];
                j++;
            }else{ //remove his
                i++;
            }
        }
        player1 = !player1;
    }

    cout << sum1 - sum2 << endl;
    return 0;
}

//