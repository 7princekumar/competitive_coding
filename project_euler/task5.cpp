//smallest multiple
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
#include <iostream>
#include <vector>
#include <cstdbool>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

bool is_prime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if((n%2==0) || (n%3==0)) return false;
    for(int i=5; i*i <= n; i+=6){
        if((n%i==0) || (n%(i+2)==0)) return false;
    }
    return true;
}


int get_spf(int n){ //spf: smallest prime factor
    if(n%2==0) return 2;
    int n_sqrt = sqrt(n);
    for(int i=3; i<=n_sqrt; i+=2){
        if(n%i == 0) return i;
    }
    return n;
}

vector<int> get_prime_factors(int n){
    vector<int> pf;
    int spf = get_spf(n);
    while(n > 1){
        pf.push_back(spf);
        n = n/spf;
        spf = get_spf(n);
    }
    return pf;
}

unordered_map<int, int> get_prime_factors_freq(int n){
    unordered_map<int, int> freq;
    vector<int> pf = get_prime_factors(n);
    for(int i = 0; i<pf.size(); i++){
        if(freq.find(pf[i]) == freq.end()){ //if not found
            freq[pf[i]] = 1;
        }else{
            freq[pf[i]]++;
        }
    }
    return freq;
}

int solve(int n){
    unordered_map<int, int> m; //prime_numer : count
    unordered_map<int, int> :: iterator itr;
    for(int i=2; i<=n; i++){
        unordered_map<int, int> local_pf_freq = get_prime_factors_freq(i); //prime_numer : count
        for(itr=local_pf_freq.begin(); itr != local_pf_freq.end(); itr++){
            if(m.find(itr->first) == m.end()){
                m[itr->first] = itr->second;
            }else{
                m[itr->first] = max(m[itr->first], itr->second);
            }
        }
    }

    int ans = 1;
    for(itr = m.begin(); itr != m.end(); itr++){
        ans *= pow(itr->first, itr->second); 
    }

    return ans;
}

#undef int
int main(){ 
#define int long long
    int n;
    cin >> n;
    cout<< solve(n) << endl;
    return 0;
}

