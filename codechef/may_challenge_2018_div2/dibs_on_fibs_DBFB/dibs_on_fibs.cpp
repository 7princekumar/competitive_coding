#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

//Title:Dibs on Fibs [DBFB]
using namespace std;

int main() {
    int T; //test cases
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T + 1; i++) {
        int M,N;
        cin >> M >> N;

        int sum1 = 0;
        int ele;
        for (int j = 0; j < M; j++) {   
            cin >> ele;
            sum1 = (sum1 %MOD + ele%MOD) %MOD;
        }

        int sum2 = 0;
        for (int j = 0; j < M; j++) {
            cin >> ele;
            sum2 = (sum2 %MOD + ele%MOD) %MOD;
        }

        //do fibonacci using those sums as initial numbers
        int result = 0, k;
        vector<int> fib;
        fib.resize(max(2,N));
        fib[0] = sum1;
        fib[1] = sum2;
        for(k=2; k<N; k++){
            fib[k] = ((fib[k-1] %MOD) + (fib[k-2]%MOD)) %MOD;  //(a+b)%m = (a%m+b%m)%m.
        }   
        result = ((fib[N-1]) * M) %MOD;

        results.push_back(result);
    } //for each test case


    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}
