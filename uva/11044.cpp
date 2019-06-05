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

  int T;
  scanf("%d", &T);
  while(T--) {
    int n,m;
    scanf("%d %d", &n, &m);
    cout << (n/3) * (m/3) << endl;

  }
  
  return 0;
}