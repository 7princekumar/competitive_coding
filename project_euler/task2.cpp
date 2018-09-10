//even fibonacci numbers
#include <iostream>
#include <vector>
#include <cstdbool>
#include <unordered_set>
using namespace std;

const int max_limit = 4000000;

//find sum of even-valued terms
long solve(){
    vector<int> dp;
    long sum = 0;

    dp.push_back(0);
    dp.push_back(1);
    for(int i=2; dp.back() < max_limit; i++){
        dp.push_back(dp[i-1] + dp[i-2]);
        if(dp.back() % 2 == 0){ //even fib
            sum += dp.back();
        }
    }

    return sum;
}



int main(){ 
    cout<< solve() << endl;
    return 0;
}