/*
id:Name: 119 - Greedy Gift Givers
Section: Medium - CP3 (Getting started - Introduction)
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=55
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
#include <map>
using namespace std;

#define MAX 10 //given

int main(){
  #ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt",  "w", stderr);
  #endif

  int members = 0, count = 0, money = 0;
  string name, who, whom;
  while(scanf("%d", &members) != EOF) { //till EOF
	map<string, pair<int, int> > names; //name -> money_spent, money_recieved
	map<string, pair<int, int> >:: iterator itr;
	vector<string> names_order;

	//read names
	for(int i=0; i<members; i++) {
	  cin >> name;
	  names_order.push_back(name); 
	  names[name] = make_pair(0,0); //initially, no money spent or recieved
	}

	//handle distributions
	for(int i=0; i<members; i++) {
	  cin >> who >> money >> count;
	  names[who].first = money;
	  int temp = money;
	  for(int j=0; j<count; j++){
		cin >> whom;
		names[whom].second += money/count;
		temp -= money/count;
	  }
	  names[who].second += temp;
	}
	
	//print results
	int temp;
	for(int i=0; i<names_order.size(); i++) {
	  temp = names[names_order[i]].second - names[names_order[i]].first;
	  cout << names_order[i] << " " << temp << endl;
	}
	cout << endl;
  }

  return 0;
}
