/*
Id     : 12554
Name   : A Special "Happy Birthday" Song!!!
Section: Easy - CP3
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3999
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

#define N 31 //given

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int n; cin >> n;
  string aud[N];
  string song[] = {"Happy", "birthday", "to", "you", 
                   "Happy", "birthday", "to", "you", 
                   "Happy", "birthday", "to", "Rujia", 
                   "Happy", "birthday", "to", "you"};

  for(int i=0; i<n; i++) {
    cin >> aud[i];
  }  

  if(n < 16) {
    for(int i=0, j; i<16; i++) {
      j = (i+n) % n;
      cout << aud[j] << ": " << song[i] << endl;
    }
  }else{
    int temp = ceil(n/16.0) * 16;
    for(int i=0, j, k; i<temp; i++) {
      k = (i+16) % 16;
      j = (i+n) % n;
      cout << aud[j] << ": " << song[k] << endl;
    }
  }

  return 0;
}
