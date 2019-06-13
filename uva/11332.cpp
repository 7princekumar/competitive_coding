/*
Id     : 11332
Name   : Summing Digits
Section: Easy - CP3
Link   : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2307
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int n, ans;
  while(scanf("%d", &n), n) {
    ans = n % 9;
    if(ans == 0){
      cout << 9 << endl;
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}