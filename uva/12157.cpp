/*
Id     : 12157
Name   : Tariff Plan
Section: Easy - CP3
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3309
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

void print_case(int count, string s, int ans) {
  cout << "Case " << count << ": " << s << " " << ans << endl;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int tc; cin >> tc;
  int count = 1;
  while(tc-- ) {
    int n; cin >> n;
    int d, mile = 0, juice = 0;
    for(int i=0; i<n; i++) {
      cin >> d;
      mile += ceil(d/29.9999) * 10;
      juice+= ceil(d/59.9999) * 15; 
    }
    if(mile == juice){
      print_case(count++, "Mile Juice", mile);
    } else if(mile < juice) {
      print_case(count++, "Mile", mile);
    } else {
      print_case(count++, "Juice", juice);
    }
  }

  return 0;
}
