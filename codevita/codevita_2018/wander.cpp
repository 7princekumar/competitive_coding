#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility> //for pair, make_pair

using namespace std;
typedef long long ll;

int fact[11] = {0};  //global
ll fact_dp(int n){
    if (n >= 0) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = i * fact[i - 1];
        }
        return fact[n];
    }
    return -1;
}

int main() {
    int M, N, K;
    int x1, y1, x2, y2;

    scanf("%d,%d,%d", &M, &N, &K);
    scanf("%d,%d,%d,%d", &x1, &y1, &x2, &y2);

    int ans;
    int nume, deno1, deno2;
    nume = fact_dp(x2 - x1 + y2 - y1);
    if(fact[x2-x1] !=0 ){
        deno1 = fact[x2-x1];
    }
    if(fact[y2-y1] !=0 ){
        deno2 = fact[y2-y1];
    }

    cout<< nume/(deno1 * deno2);
    

    return 0;
}

//