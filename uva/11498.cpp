#include <iostream>
#include <string>
#include <climits>
using namespace std;

string check_quadrant(int x, int y){
  if(x==0 || y==0) {
    return "divisa";
  }else if(x > 0 && y > 0) {
    return "NE";
  }else if(x < 0 && y > 0) {
    return "NO";
  }else if(x < 0 && y < 0) {
    return "SO";
  }else{
    return "SE";
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  int tc;
  int n,m;
  int x,y;
  while(scanf("%d", &tc), tc) { //while tc != 0
    scanf("%d %d", &n, &m);
    while(tc--){
      scanf("%d %d", &x, &y);
      //change cordinate reference point
      x = x - n;
      y = y - m;
      cout << check_quadrant(x, y) << endl;
    }
  }
  
  return 0;
}