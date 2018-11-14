#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int P1, P2, K;
        cin >> P1 >> P2 >> K;
        if(((P1 + P2) / K) % 2 == 0){
            cout << "CHEF\n";
        }else{
            cout << "COOK\n";
        }
    }
    return 0;
}