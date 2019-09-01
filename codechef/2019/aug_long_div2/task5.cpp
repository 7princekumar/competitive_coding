#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdbool>
using namespace std;

typedef vector<int> vi;

template <typename T>
void print_v(T v){
  for(int i=0; i<v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w",  stderr);
#endif
    int tc;
    cin >> tc;
    while(tc--) {
      int n; cin >> n;
      vi v;
      vi prefix_xor; prefix_xor.resize(n);
      int ele;
      for(int i=0; i<n; i++){
        cin >> ele; v.push_back(ele);
      }
      prefix_xor[0] = v[0];
      for(int i=1; i<n; i++){
        prefix_xor[i] = prefix_xor[i-1] ^ v[i];
      }
      print_v<vi>(prefix_xor);
    }
    return 0;
}