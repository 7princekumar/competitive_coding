#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<int> v;
  int ele;
  for(int i=0;i<n1+n2+n3; i++) {
    cin >> ele;
    v.push_back(ele);
  }
  set<int> ans;
  sort(v.begin(), v.end());
  int count = 1;
  int curr = v[0];
  for(int i=1; i<n1+n2+n3; i++) {
    if(v[i] == v[i-1]){
      count++;
    }else{
      count = 1;
    }
    if(count >= 2){
      ans.insert(v[i]);
    }
  }
  cout << ans.size() << endl;
  for(set<int>::iterator itr = ans.begin(); itr != ans.end(); itr++){
    cout << *itr << endl;
  }
  return 0;
}