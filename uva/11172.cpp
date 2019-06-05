#include <iostream>
#include <cstdbool>
#include <cmath>
#include <string>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int tc;
  scanf("%d", &tc);

  while(tc--) {
    long long a, b;
    cin >> a >> b;
    if(a == b) {
      cout << "=" << endl;
    }else if(a > b) {
      cout << ">" << endl;
    }else {
      cout << "<" << endl;
    }
  }
  
  return 0;
}