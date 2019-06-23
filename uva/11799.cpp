/*
Id     : 11799
Name   : Horror Dash
Section: Easy - CP3
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2899
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int tc;
  cin >> tc;
  int count = 0;
  while(tc-- ) {
    count++;
    int n; //number of students acting as scary creatures
    cin >> n;
    int s[10005];
    for(int i=0; i<n; i++) {
      cin >> s[i];
    }
    cout << "Case " << count << ": " << *max_element(s, s+n) << endl;
  }

  return 0;
}
