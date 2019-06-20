/*
Id     : 11764
Name   : Jumping Mario
Section: Easy - CP3
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2864
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
  while(tc--) {
    count++;
    int n; //number of walls
    cin >> n;
    int h[51];
    int high = 0, low = 0;
    for(int i=0; i<n; i++) {
      cin >> h[i];
      if(i > 0 && h[i] != h[i-1]){
        if(h[i] > h[i-1]){
          high++;
        }else{
          low++;
        }
      }
    }
    cout << "Case " << count << ": " << high << " " << low << endl;
  }

  return 0;
}
