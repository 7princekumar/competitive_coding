#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <cstdio>

using namespace std;

int highestPowerof2(int n)
{
    int res = 0;
    for (int i=n; i>=1; i--)
    {
        // If i is a power of 2
        if ((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}




int main() {
    int T; //test cases
    cin >> T;
    vector< vector<int> > results;

    for (int i = 1; i < T+1; i++) {
        vector< int> local_results;
        int N, K;
        scanf("%d %d", &N, &K);
        // cin >> N >> K;
        
        //----write from here-----
        int temp = highestPowerof2(K);
        
        int max_2_power = log2 (temp);
        while (max_2_power >= 0){
            local_results.push_back(pow(2, max_2_power));
            max_2_power--;
        }
        int local_results_size = local_results.size();
        while(local_results_size < N){
            local_results.push_back(1);
            local_results_size++;
        }
        results.push_back(local_results);

    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        for(int j=0; j< results[i].size(); j++){
            printf("%d ", results[i][j]);
            // cout << results[i][j] << " ";
        }
        cout<<endl;
        
    }

    return 0;
}

//