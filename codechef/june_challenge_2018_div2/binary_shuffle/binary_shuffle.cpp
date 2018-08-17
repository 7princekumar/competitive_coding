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
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        int A, B;
        cin >> A >> B;

        //----write from here-----
        int tempA = A;
        int tempB = B-1;

        int countA = 0;
        int countB = 0;

        while(tempA){
            countA++;
            tempA = tempA >> 1;
        }
        while(tempB){
            countB++;
            tempB = tempB >> 1;
        }

        cout<<"countA: "<<countA<<endl;
        cout<<"countB: "<<countB<<endl;

        int freq1A = __builtin_popcount(tempA);
        int freq1B = __builtin_popcount(tempB);

        if(freq1A != freq1B){
            results.push_back(-1);
            break;
        } else {
            for(int j=0; j< max(countA, countB); i++){
                
            }
        }



    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//