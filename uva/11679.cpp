/*
Id     : 11679
Name   : Sub-prime
Section: Easy - CP3
Link   : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2726
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 21

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int b; //number of banks
  int n; //number of debentures
  while(scanf("%d %d", &b, &n), b!=0 && n!=0) {
    int R[MAX]; //monetary reserves of each one of the B banks
    
    for(int i=0; i<b; i++) {
      cin >> R[i];
    }

    int d; //debtor bank
    int c; //creditor bank
    int v; //debenture value
    for(int i=0; i<n; i++) {
      cin >> d >> c >> v;
      R[c-1] += v;
      R[d-1] -= v;
    }

    int flag = 0;
    for(int i=0; i<b; i++) {
      if(R[i] < 0){
        flag = 1;
        break;
      }
    }

    if(flag == 1){
      cout << "N" << endl;
    } else {
      cout << "S" << endl;
    }
  }
  

  return 0;
}
