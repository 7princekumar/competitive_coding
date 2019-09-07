#include <iostream>
using namespace std;

//find x to the power n (i.e. x^n)
int power(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    int small_output = power(x, n-1);
    int output = x * small_output;
    return output;
}

//print number from 1 to n in increasing order recursively.
void print(int n){
    if(n == 0){
        return;
    }
    print(n - 1);
    cout << n << " ";
}

//find out and return the number of digits present in a number recursively
int count(int n){
    if(n == 0){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}

int main(){
  int x, n; cin >> x >> n;
  cout << power(x, n) << endl;
  cin >> n;
  print(n); cout << endl;
  cin >> n;
  cout << count(n) << endl;
  
  return 0;
}

/*
sample input: 
3 4
5
6543
*/

/*
sample output:
81
1 2 3 4 5
4
*/