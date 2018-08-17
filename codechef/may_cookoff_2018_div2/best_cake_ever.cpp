#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <cstdio>

using namespace std;


void print_i_v(vector<long long> &v){
    for(int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}



int main() {
    int T; //test cases
    cin >> T;
    vector< vector<long long> > results;

    for (int i = 1; i < T+1; i++) {
        vector< long long> local_results;
        long long N, K;
        //scanf("%d %d", &N, &K);
        cin >> N >> K;
        //----write from here-----
        long long temp = K;
        
        int max_2_power = log2 (temp) - 1;
        local_results.push_back(K);
        int local_results_size = 1;

        while (local_results_size<N &&  max_2_power >= 0){
            local_results.push_back(pow(2, max_2_power));
            local_results_size++;
            max_2_power--;
        }
        //int local_results_size = local_results.size();
        while(local_results_size < N){
            local_results.push_back(1);
            local_results_size++;
        }
        results.push_back(local_results);
        //print_i_v(local_results);

    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        for(int j=0; j< results[i].size(); j++){
            printf("%lld ", results[i][j]);
            // cout << results[i][j] << " ";
        }
        cout<<endl;
        
    }

    return 0;
}

//