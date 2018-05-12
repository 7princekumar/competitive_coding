#include <iostream>
#include <vector>
typedef long long ll;
#define MOD 1000000007

//Title:Dibs on Fibs [DBFB]
using namespace std;

int main() {
    int T; //test cases
    cin >> T;
    vector<ll> results;

    for (int i = 1; i < T + 1; i++) {
        int M,N;
        cin >> M >> N;

        //get the list of elements for seqA
        vector<ll> seqA;
        seqA.clear();
        for (int j = 0; j < M; j++) {
            ll ele;
            cin >> ele;
            seqA.push_back(ele);
        }

        //get the list of elements for seqB
        vector<ll> seqB;
        seqB.clear();
        for (int j = 0; j < M; j++) {
            ll ele;
            cin >> ele;
            seqB.push_back(ele);
        }

        //----write from here-----
        ll result = 0;
        for(int j=0; j<M; j++){
            for(int k=0; k<M; k++){
                vector<ll> fib;
                fib.resize(N+1);
                fib[0] = 0;//padding
                fib[1] = seqA[j];
                fib[2] = seqB[k];
                for(int l=3; l<=N; l++){
                    fib[l] = ((fib[l-1] %MOD) + (fib[l-2] %MOD)) %MOD;
                }
                result = (result %MOD + fib[N] %MOD) %MOD;    //(a+b)%m = (a%m+b%m)%m.
            }
        }
        results.push_back(result);
    } //for each test case


    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}
