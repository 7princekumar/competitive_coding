#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map> //pairs
#include <unordered_set> //hash

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
typedef long long ll;
//int max= *max_element(v.begin(), v.end());

using namespace std;

void print_i_v(vector<int> &v){
    for(int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}







int main() {
    int T; //test cases
    T = 1;

    for (int i = 1; i < T+1; i++) {
        ll x, y;
        cin >> x >> y;

        //cout<<"t1: "<<t1 << endl;
        //cout<<"t2: "<<t2 << endl;
        if( (y* log(x)) == (x* log(y))) {
            cout<<'=';
        } else if( (y* log(x)) < (x* log(y)) ){
            cout<<'<';
        } else {
            cout<<'>' ;
        }
        





    } //for each test case

    return 0;
}

//