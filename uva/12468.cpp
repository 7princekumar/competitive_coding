/*
Id     : 12468
Name   : Zapping
Section: Easy - CP3
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3912
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


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int a, b; 
  while(scanf("%d %d", &a, &b), a != -1 && b != -1) {
    a++; b++;
    cout << min(abs(a-b), abs( (min(a,b) +100) - max(a,b) )%100) << endl;
  }

  return 0;
}

// 0 1 2 3 4 ...97 98 99 0 1 2 3 ...
// 3 9 -> 4 10
// min(6, (4 + 100)%100