#include <iostream>
#include <string>
using namespace std;

int handle(string s){
  int penalty = 0;
  if(s[0] != 'o') penalty++;
  if(s[1] != 'n') penalty++;
  if(s[2] != 'e') penalty++;
  if(penalty > 1) return 2;
  else return 1;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int tc;
  string s;
  scanf("%d", &tc);
  while(tc--) {
    cin >> s;
    if(s.length() > 3) {
      cout << "3" << endl;
    } else {
      cout << handle(s) << endl;
    }
  }
  
  return 0;
}