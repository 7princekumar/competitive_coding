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

int get_sum(int n){
    return (n*(n+1))/2;
}

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

void print_exept(int k, int n){
    for(int i=1; i<=n; i++){
        if(i != k)
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int sum = get_sum(n);
    bool found = false;
    for(int i=1; i<=n && !found; i++){
        if(gcd(sum, i) > 1){
            found = true;
            cout << "Yes\n";
            cout << 1 <<" "<< i << endl;
            cout << n-1 << " "; print_exept(i, n);
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

//