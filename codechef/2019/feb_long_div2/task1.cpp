//https://www.codechef.com/FEB19B/problems/HMAPPY2
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdbool>
using namespace std;

//appy - divisible by A (not by B)
//chef - divisible by B (not by A)
//don't solve - divisible by both A, B
//atleast K problems
#define MAX 1000005

int main(){
    int T; cin >> T;
    while(T--){
        int N, A, B, K;
        cin >> N >> A >> B >> K;
        int problems_solved = N/A + N/B - N/(A*B);
        if(problems_solved < K){
            cout << "Lose\n";
        }else{
            cout << "Win\n";
        }
    }
    return 0;
}