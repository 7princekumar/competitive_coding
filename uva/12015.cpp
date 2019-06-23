/*
Id     : 12015
Name   : Google is Feeling Lucky
Section: Easy - CP3
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3166
*/
#include <iostream>
#include <cstring>
#include <cstdbool>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void print_top(vector<pair<int, string> >& pq) {
  int big = INT_MIN;
  for(int i=0; i<pq.size(); i++) {
    big = max(big, pq[i].first);
  }
  for(int i=0; i<pq.size(); i++) {
    if(big == pq[i].first) {
      cout << pq[i].second << endl;
    }
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt",  "w", stderr);
  #endif

  int tc;
  cin >> tc;
  int count = 1;
  while(tc--) {
    int n=10; //given
    string str;
    int score;
    vector< pair<int, string> > pq;
    for(int i=0; i<n; i++) {
      cin >> str >> score;
      pq.push_back(make_pair(score, str));
    }
    cout << "Case #"<< count++ <<":" << endl;
    print_top(pq);
    
  }  

  return 0;
}
