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
    int T; //test cases
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        string front; cin>> front;
        string back;  cin>> back;

        //----write from here-----
        if( ((front[0] == 'b') || (back[0] == 'b')) && 
            ((front[1] == 'o') || (back[1] == 'o')) && 
            ((front[2] == 'b') || (back[2] == 'b'))){
                results.push_back(1);
        }else{
            results.push_back(0);
        }

    } //for each test case

    //print results
    for (unsigned int i = 0; i < results.size(); i++){
        if(results[i]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }     
    }

    return 0;
}

//