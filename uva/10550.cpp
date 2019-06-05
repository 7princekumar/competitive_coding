#include <iostream>
#include <cstdbool>
#include <string>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  //40 units -> 360 degree
  //1 unit   -> 9 degree

  int start, first, second, third;
  int first_sol;  //rotates clockwise, but number moves anti-clockwise
  int second_sol; //rotates anticlockwise, but number moves clockwise
  int third_sol;  //rotates clockwise, but number moves anti-clockwise
  
  while(scanf("%d %d %d %d", &start, &first, &second, &third), start||first||second||third) {
    first_sol = 720 + (((start - first + 40)%40)* 9);  //think anti-clock: initial_pos - destination
    second_sol= 360 + (((second - first + 40)%40)* 9); //think clockwise:  destination - initial_pos
    third_sol = ((second - third + 40)%40)* 9;         //think anti-clock
    cout << first_sol + second_sol + third_sol << endl;
  }
  
  return 0;
}