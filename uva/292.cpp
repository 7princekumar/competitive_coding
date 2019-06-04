#include <iostream>
#include <cstdbool>
#include <string>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  string s;
  bool first = true;
  while(getline(cin, s)) {
    for(int i=0; i<s.length(); i++) {
      if(s[i] == '"') {
        if(first) {
          cout << "``";
        } else {
          cout << "''";
        }
        first = !first;
      } else {
        cout << s[i];
      }
    }
    cout << endl;
  }
  return 0;
}