#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int* population = new int[n];
  for(int i=0; i<n; i++) {
    cin >> population[i];
  }

  int first, second, total_pop;
  for(int i=0; i<n/2; i++){
    first = i;
    second = n-i-1;
    total_pop = population[first] + population[second];
    cout << total_pop / 10;
    cout << " ";
    cout << total_pop % 10 << endl;
  }

  delete[] population;
  population = NULL;
  return 0;
}