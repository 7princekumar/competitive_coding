#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    cin >> T;
    vector<double> results;

    for (int i = 1; i < T+1; i++) {
        int N,A,B;
        cin >> N >> A >> B;

        //get the list of elements
        vector<int> elements;
        elements.clear();
        for (int j = 0; j < N; j++){
            int ele;
            cin >> ele;
            elements.push_back(ele);
        }

        //----write from here-----
        double pA = 0;
        double pB = 0;

        pA = count(elements.begin(), elements.end(), A);
        pB = count(elements.begin(), elements.end(), B);

        // cout<<"pa: "<<pA<<endl;
        // cout<<"pb: "<<pB<<endl;

        double result = (pA * pB)/(N*N); 
        // cout<<"result: "<<result<<endl;
        results.push_back(result);

    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//