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

  int tc;
  cin >> tc;
  string s;
  int m;   //money
  int ans = 0;
  while(tc-- ){
    cin >> s;
    if(s == "donate") {
      cin >> m; 
      ans += m;
    } else {
      cout << ans << endl;
    }
  }
  
  return 0;
}