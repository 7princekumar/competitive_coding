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

void print_ii_umap(unordered_map<int, int> m){
    unordered_map<int, int> :: iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++){
        cout << "("<< itr->first << ": " << itr->second << ")  ";
    }
    cout << endl;
}



int main() {
    int T; //test cases
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        int N;
        cin >> N;

        //get the list of elements
        vector<int> elements;
        elements.clear();
        for (int j = 0; j < N; j++){
            int ele;
            cin >> ele;
            elements.push_back(ele);
        }

        //----write from here-----





    } //for each test case

    //print results
    for (unsigned int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//