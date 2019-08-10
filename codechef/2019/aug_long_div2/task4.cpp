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

typedef long long ll;

void print_vll(vector<ll>& v){
  for(int i=0; i<v.size(); i++) {
    cerr << v[i] << "\t";
  }
  cerr << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w",  stderr);
#endif
    
    int tc; cin >> tc;
    while(tc-- ){
      int n; cin >> n;
      vector<ll> c;
      vector<ll> h;
      vector<ll> l;
      ll ele;
      for(int i=0; i<n; i++) {
        cin >> ele; c.push_back(ele);
        l.push_back(0);
      }
      for(int i=0; i<n; i++) {
        cin >> ele; h.push_back(ele);
      }
      int start, end;
      for(int i=0; i<n; i++){
        start = i - c[i];
        if(start < 0) start = 0;
        end   = i + c[i];
        l[start] += 1;
        if(end + 1 < n){
          l[end + 1] -= 1;
        }
      }
      
      for(int i=1; i<n; i++){
        l[i] += l[i-1];
      }

      sort(l.begin(), l.end());
      sort(h.begin(), h.end());
      bool flag = false;
      for(int i=0; i<n; i++) {
        if(l[i] != h[i]){
          flag = true;
          break;
        }
      }
      if(flag == true){
        cout << "NO" << endl;
      }else{
        cout << "YES" << endl;
      }
    }
    return 0;
}
//hint: https://www.geeksforgeeks.org/print-modified-array-multiple-array-range-increment-operations/