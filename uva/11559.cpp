/*
Id     : 11559
Name   : Event Planning
Section: Easy - CP3
Link   : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2595
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

  int n, b, h, w, a, p, ans; //participants(count), budget, hotels(count), weeks(count)
  while(scanf("%d %d %d %d", &n, &b, &h, &w) == 4) {
    ans = INT_MAX;
    for(int i=0; i<h; i++){
      cin >> p; //price of helel room
      for(int j=0; j<w; j++){ //available beds
        cin >> a;
        if(a >= n) {
          ans = min(ans, n * p);
        }
      }
    }
    if(ans != INT_MAX && ans < b) {
      cout << ans << endl;
    } else {
      cout << "stay home" << endl;
    }
  }
  

  return 0;
}

//n >= ab with min 'p'  -> should fit within budget