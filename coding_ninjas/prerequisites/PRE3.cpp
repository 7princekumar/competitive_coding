#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  //initialize and populate dynamic 2d array
  int** a = new int*[n]; //pointer to array of n arrays
  for(int i=0; i<n; i++){
    a[i] = new int[n]; //point each element to an array
    for(int j=0; j<n; j++){
      cin >> a[i][j];
    }
  }

  int sum = 0; //ans

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i==0 || j==0 || i==n-1 || j==n-1 || i==j || (i+j==n-1)){
        sum += a[i][j];
      }
    }
  }
  
  cout << sum << endl;


  //delete the memory
  for(int i=0; i<n; i++){
    delete a[i];
  }
  delete[] a;

  return 0;
}