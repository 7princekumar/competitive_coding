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

  int tc, state=0;
  string s;
  cin >> tc;
  while(tc-- ){
    cin >> s; 
    if(s[s.length() -1] == '5') cout << "-" << endl;
    else if(s[0] == '9') cout << "*" << endl;
    else if(s[0] == '4' || s[0] == '7') cout << "+" << endl;
    else if(s[0] == '1') {
      if(s.length() > 1 && s[1] == '9') cout << "?" << endl;
      else cout << "+" << endl;
    }

  }
  
  return 0;
}