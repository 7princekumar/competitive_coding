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
  while(getline(cin, s)) {
    cout << s << endl;
  }  
  return 0;
}