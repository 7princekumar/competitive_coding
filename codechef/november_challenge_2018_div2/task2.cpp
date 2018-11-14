#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        long long deno = pow(2, N);
        long long nume = pow(2, N-1);
        if(N == 1 || N == 2){
            cout << 1 << " " << deno << " ";
        }else{
            if(N%2 == 0)
                cout << nume + 1 << " " << deno << " ";
            else
                cout << nume - 1 << " " << deno << " ";
        }   
    }
    return 0;
}