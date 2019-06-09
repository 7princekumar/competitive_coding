#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  string s;
  int count = 1;
  while(getline(cin, s), s!= "*") {
    if(s == "Hajj") cout << "Case " << count++ << ": Hajj-e-Akbar" << endl;
    else cout << "Case " << count++ << ": Hajj-e-Asghar" << endl;
  }
  
  return 0;
}