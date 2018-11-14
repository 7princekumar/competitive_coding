#include <iostream>
#include <vector>
#include <string>
#include <cstdbool>
using namespace std;

int n;
string a;

bool check(int sum, int pos){
    int local = 0;
    bool result = false;
    for(int i=pos; i<n; i++){
        // cout << "local_sum: "<< local << endl; ///
        local += a[i] - '0';
        if(local == sum){
            result = true;
            local = 0;
        }
        if(local > sum){
            return false;
        }
    }
    return (local == 0 && result);
}


int main(){
    cin>> n >> a;

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i] - '0';
        // cout << "checking for sum: " << sum << endl; ///
        if(check(sum, i+1) == true){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    
    return 0;
}