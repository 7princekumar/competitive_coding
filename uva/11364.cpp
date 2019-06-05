#include <iostream>
#include <climits>
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
    int n; cin >> n;
    int max = INT_MIN;
    int min = INT_MAX;
    int ele;
    for(int i=0; i< n; i++) { //calc min and max on the go. (no need to sort)
      cin >> ele;
      if(ele > max) max = ele;
      if(ele < min) min = ele;
    }
    cout << 2 * (max - min) << endl;
  }
  
  return 0;
}