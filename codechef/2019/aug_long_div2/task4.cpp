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

void expand(vector<ll>& v, int pos, int n){
  v[pos] += 1;
  for(int i=1; i<=n; i++){
    if(pos + i < v.size()){ //go right
      v[pos + i] += 1;
    }
    if(pos - i >= 0){       //go left
      v[pos - i] += 1;
    }
  }
}

void print_vll(vector<ll>& v){
  for(int i=0; i<v.size(); i++) {
    cerr << v[i] << " |";
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
      for(int i=0; i<n; i++){
        expand(l, i, c[i]);
      }
      // cerr << "Test Case: " << tc << endl;
      // cerr << "After expansion l: ";
      // print_vll(l); //test
      sort(l.begin(), l.end());
      sort(h.begin(), h.end());
      // cerr << "l: "; print_vll(l); //test
      // cerr << "h: "; print_vll(h); //test
      // cerr << endl;
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