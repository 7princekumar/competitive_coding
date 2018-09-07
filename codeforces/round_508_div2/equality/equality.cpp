#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map> //pairs
#include <unordered_set> //hash
#include <utility> //for pair, make_pair

using namespace std;

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
typedef long long ll;
//int max= *max_element(v.begin(), v.end());


void print_i_v(vector<int> &v){
    for(unsigned int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}



int main() {
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<int> freq;
    freq.resize(26);

    for(int i=0; i<s.length(); i++){
        freq[s[i] - 'A']++;
    }

    cout << (*min_element(freq.begin(), freq.begin() + k)) * k;

    return 0;
}

//