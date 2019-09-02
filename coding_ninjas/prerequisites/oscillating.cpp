//Oscillating Prices of "Chakri"
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int* a = new int[n]; //price list for coming N days
  for(int i=0; i<n; i++){ 
    cin >> a[i];
  }
  
  int local_gap = 0, max_gap = 0;
  
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      local_gap = max(local_gap, a[j] - a[i]);
      max_gap   = max(max_gap, local_gap);
    }
  }

  cout << max_gap << endl;
  return 0;
}

// 7
// 62 63 70 66 64 68 61