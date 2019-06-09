#include <iostream>
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
  int l,w,h;
  int count = 1;
  while(tc-- ) {
    cin >> l >> w >> h;
    if(l > 20 || w > 20 || h > 20)
      cout << "Case " << count++ << ": " << "bad" << endl;
    else
      cout << "Case " << count++ << ": " << "good" << endl;
  }
  
  return 0;
}