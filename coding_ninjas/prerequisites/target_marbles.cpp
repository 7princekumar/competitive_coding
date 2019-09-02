#include <bits/stdc++.h>
using namespace std;

void print_subset(int* a, int n, int l, int r){
  for(int i=l; i<=r && i<n; i++){
    cout << a[i] << " ";
  }
}

int main(){
  int n; cin >> n;
  int tn; cin >> tn; //target_number
  
  int* arr = new int[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int local_sum = arr[0];
  int start_index = 0;
  bool done = false;
  for(int i=1; i<=n && !done; i++){
      if(local_sum > tn){
          while(local_sum > tn && start_index < i-1){
            local_sum -= arr[start_index];
            start_index++;
          }
      }
      
      if(local_sum == tn){
          done = true;
          cout << "true" << endl;
          print_subset(arr, n, start_index, i-1);
          cout << endl;
      }
      else{
          local_sum += arr[i];
      }

  }
  if(!done) cout << "false" << endl;

  delete[] arr; arr = NULL;
  return 0;
}

// 10 10
// 0 9 5 3 1 4 1 2 3