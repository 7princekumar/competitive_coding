#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define int long long

#undef int
int main(){
#define int long long
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int bits = 0;
        int nibbles = 0;
        int bytes = 0;

        int t = N / 26;
        // cout << "turns: " << t << endl;
        int r = N % 26;
        // cout << "remaining: " << r << endl;
        if(r == 0){
            bytes = pow(2, t-1);
        }else if(r <= 2){
            bits = pow(2, t);
        }else if(r <= 10){
            nibbles = pow(2, t);
        }else{
            bytes = pow(2,t);
        }
        cout << bits << " " << nibbles << " " << bytes;
        cout << endl;
    }
    return 0;
}