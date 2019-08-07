#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdbool>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w",  stderr);
#endif
    
    int tc; cin >> tc;
    while(tc-- ){
      long long n, k; cin >> n >> k; // n = ck, c is any constant
      //n apples
      //k box
      //print YES if different, otherwise NO
      //the first candidate puts exactly one apple in each box
      //second one chooses a random box |||with the smallest number||| of apples and puts K apples in it.
      //(n % (k*k)) == 0
      long long c1 = n/k;
      if(k==1 || c1 % k == 0){
        cout << "NO" << endl;
      }else{
        cout << "YES" << endl;
      }
    }
    return 0;
}