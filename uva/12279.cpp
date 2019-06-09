#include <iostream>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int n, ans, ele;
  int count = 1;
  while(scanf("%d", &n), n){ //while n != 0
    ans = 0;
    for(int i=0; i<n; i++){
      scanf("%d", &ele);
      (ele > 0) ? ans++ : ans--;
    }
    cout << "Case " << count++ << ": " << ans << endl;
  }
  
  return 0;
}