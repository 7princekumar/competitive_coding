#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        int x1,x2,x3,v1,v2;
        cin >> x1 >> x2 >> x3 >> v1 >> v2;

        //----write from here-----
        float t1 =  abs(x3 - x1)/float(v1);
        float t2 =  abs(x3 - x2)/float(v2);
        if(t1 == t2){
            results.push_back(0);
        } else if( t1 > t2){
            results.push_back(1);
        } else {
            results.push_back(2);
        }



    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        if(results[i] == 0){
            cout<<"Draw"<<endl;
        } else if (results[i] == 1){
            cout<<"Kefa"<<endl;
        } else {
            cout<<"Chef"<<endl;
        }
    }

    return 0;
}

//