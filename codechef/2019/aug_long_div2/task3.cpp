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

bool is_even(int count){
  return count % 2 == 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w",  stderr);
#endif
    
    int tc; cin >> tc;
    while(tc-- ){
      string s;
      cin >> s;
      //solution: String with even no. of ones, LOSE, else WIN
      if(is_even(count(s.begin(), s.end(), '1'))){
        cout << "LOSE" << endl;
      }else{
        cout << "WIN" << endl;
      }
    }
    return 0;
}