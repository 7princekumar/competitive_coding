/*
Id     : 10114
Name   : Loansome Car Buyer
Section: Easy - CP3
Link   : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=1055
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define MAX 105

void fill(float* array, float value, int n) {
  for(int i=0; i< n; i++) {
    array[i] = value;
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int month, n;
  double down_payment, price;

  int index, ans = 0; //months
  float r, rate[MAX];
  double curr_worth, owes;
  while(scanf("%d %lf %lf %d", &month, &down_payment, &price, &n), month > 0) {
    for(int i=0; i<n; i++) {
      scanf("%d %f", &index, &r); 
      fill(rate + index, r, month - index);
    }
    
    owes = price;
    curr_worth = (1 - rate[0]) * (price + down_payment);
  
    for(int i=0; i<month; i++) {
      curr_worth *= 1 - rate[i+1];
      owes -= price/month;
      // cout << curr_worth << "   " << owes << endl; //test
      if(curr_worth > owes) {
        if (i == 0) cout << "1 month" << endl;
        else cout << i + 1 << " months" << endl;
        break;
      }
      
    }
  }
  return 0;
}