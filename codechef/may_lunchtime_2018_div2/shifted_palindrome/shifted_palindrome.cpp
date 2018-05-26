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
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        string str;
        int K;
        cin>> str;

        //----write from here-----
        string r_str = str;
        int local_count = 0;
        int j =0;
        int firstDone = 0; //true
        // while((str != r_str) || (firstDone == 0)){
        while((j != str.length()) || (firstDone == 0)){
            j++;
            firstDone = 1;
            if (r_str == string(r_str.rbegin(), r_str.rend())) {
                local_count++;
                // cout<<r_str<< endl; //////DELETE ME
            }
            rotate(r_str.begin(), r_str.begin()+1, r_str.end());
        }
        results.push_back(local_count);



    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//