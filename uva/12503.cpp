/*
Id     : 12503
Name   : Robot Instructions
Section: Easy - CP3
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3947
*/
#include <iostream>
#include <cstring>
#include <cstdbool>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 101 //100 given

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int tc; cin >> tc;
  while(tc-- ) {
    int n; cin >> n;
    string s1, s2;
    int d, ans = 0, query[MAX]; //ans
    memset(query, 0, sizeof(query));

    for(int i=0; i<n; i++) {
      cin >> s1;
      if(s1 == "LEFT") {
        ans--;
        query[i+1] = -1;
      }else if(s1 == "RIGHT") {
        ans++;
        query[i+1] = 1;
      }else {
        cin >> s2 >> d;
        ans += query[d];
        query[i+1] = query[d];
      }
    }
    cout << ans << endl;
  }

  return 0;
}
