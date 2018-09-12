//largest palindrome product
//Find the largest palindrome made from the product of two 3-digit numbers
#include <iostream>
#include <vector>
#include <cstdbool>
#include <cmath>
#include <unordered_set>
using namespace std;

bool isPalindrome(int n){
    string s = to_string(n);
    for(int i=0; i<s.length()/2; i++){
        if(s[i] != s[s.length()-1 -i]){
            return false;
        }
    }
    return true;
}

int solve(){
    int start = 100;
    int end = 999;
    int num;
    int ans = 0;
    for(int i=start; i<end + 1; i++){
        for(int j=start; j<end + 1; j++){
            num = i * j;
            if(isPalindrome(num)){
                ans = max(ans, num);
            }
        }
    }
    return ans;
}

int main(){ 
    cout<< solve() << endl;
    return 0;
}