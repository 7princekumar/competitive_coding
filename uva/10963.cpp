/*
Id     : 10963
Name   : The Swallowing Ground
Section: Easy - CP3
Link   : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=1904
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

  int tc;
  int count = 0;
  cin >> tc;
  cerr << "tc: " << tc << endl; // 
  while(tc-- ){
    count++;
    int w;
    cin >> w;
    cerr << "W: " << w << endl; //
    int y1, y2;
    cin >> y1 >> y2;
    cerr << y1 << " " << y2 << endl;
    int first_gap = abs(y1-y2);

    if(w == 1){
      if(count == 1){
        cout << "yes" << endl;
      }else{
        cout << "\nyes" << endl;
      }
      continue;
    }
    
    int found = 0;
    for(int i=1; i<w; i++) {
      cin >> y1 >> y2;
      cerr << y1 << " " << y2 << endl;
      if(abs(y1 - y2) != first_gap){
        found = 1;
      }
    }
    if(!found){
      if(count == 1){
        cout << "yes" << endl;
      }else{
        cout << "\nyes" << endl;
      }
    }else{
      if(count == 1){
        cout << "no" << endl;
      }else{
        cout << "\nno" << endl;
      }
    }
  }

  return 0;
}