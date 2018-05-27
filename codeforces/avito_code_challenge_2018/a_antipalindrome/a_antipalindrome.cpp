#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
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
    T= 1;
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        string str;
        cin>>str;

        int len = 0;
        while(( str == string(str.rbegin(), str.rend() )) && (str.length() > 0)){
            str.pop_back();
        }

        results.push_back(str.length());


    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//