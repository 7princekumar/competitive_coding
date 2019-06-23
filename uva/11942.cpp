/*
Id     : 11942
Name   : Lumberjack Sequencing
Section: Easy - CP3
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3093
*/
#include <iostream>
#include <cstring>
#include <cstdbool>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

bool compare(int a, int b) {
  return a > b;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int tc; cin >> tc;
  cout << "Lumberjacks:" << endl;
  while(tc--) {
    int a[10];
    for(int i=0; i<10; i++){
      cin >> a[i];
    }

    if(is_sorted(a, a+10) || is_sorted(a, a+10, compare)){
      cout << "Ordered" << endl;
    }else{
      cout << "Unordered" << endl;
    }
  }

  return 0;
}
