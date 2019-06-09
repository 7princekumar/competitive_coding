#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int tc;
  scanf("%d", &tc);
  int a[3];
  int count = 1;
  while(tc--) {
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sort(a, a+3);
    cout << "Case " << count++ << ": "<< a[1] << endl;
  }
  
  return 0;
}