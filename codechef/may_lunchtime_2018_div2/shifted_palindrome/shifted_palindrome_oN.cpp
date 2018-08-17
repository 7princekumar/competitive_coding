#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
typedef long long ll;
//int max= *max_element(v.begin(), v.end());

using namespace std;

void print_i_v(vector<ll> &v){
    for(ll j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

string create_string(string s){
    string T = "#";
    for(int i=0; i<s.length(); i++){
        T.push_back(s[i]);
        T.push_back('#');
    }
    return T;
}


int main() {
    int TT; //test cases
    cin >> TT;
    vector<ll> results;

    for (int ii = 1; ii < TT+1; ii++) {
        string s;
        cin>> s;
        ll n = s.length();

        string s2 = s + s;

        //now find the palindrome of length 'n' in s2
        string T = create_string(s2);
        vector<ll> P(T.length());
        ll C =0;
        ll R =0;
        ll i;
        ll i_mirror;

        for(ll i=1; i<T.length(); i++){

            //1. update P[i]
            i_mirror = 2*C - i; // c - (i-c)
            if(i < R){
                ll d = R - i;
                P[i] = min(d, P[i_mirror]);
            } else {
                P[i] = 0;
            }

            //2. expand around i
            while( T[i -1 - P[i]] == T[i+1+P[i]] ){
                P[i]++;
            }

            //3. update C,R if out of R
            if(P[i] > R- i){
                C = i;
                R = i + P[i];
            }
        }

        int local_count = 0;
        for(int i=0; i<T.length(); i++){
            if(P[i] >= n){
                local_count++;
            }
        }

        print_i_v(P);
        results.push_back(local_count);


    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//