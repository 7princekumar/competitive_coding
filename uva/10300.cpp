/*
Id     : 10300
Name   : Ecological Premium
Section: Easy - CP3
Link   : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=1241
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int tc;
  cin >> tc;
  while(tc-- ){
    int f;
    cin >> f; // num of farmers
    int ans = 0;
    while(f-- ){
      int size_of_farm, n, factor;
      cin >> size_of_farm >> n >> factor;
      float premium = size_of_farm * factor;
      ans += premium;
    }
    cout << ans << endl;
  }

  return 0;
}