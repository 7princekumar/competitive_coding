#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int tc;
  scanf("%d", &tc);
  int n;
  while(tc--){
    scanf("%d", &n);
    printf("%d\n", ((abs((((((n * 567) / 9) + 7492) * 235) / 47) - 498) % 100)) /10);
  }
  
  return 0;
}