#include <bits/stdc++.h>
using namespace std;

// arr - input array
// size - size of array
void print(int* a, int n){
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int MissingNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int zero_count = 0;
    for(int i=0; i<size; i++) {
        if(arr[i] == 0) {
            zero_count++;
            if(zero_count > 1) return 0;
        }
        
        if(arr[abs(arr[i])] < 0){
            return abs(arr[i]);
        }
        arr[abs(arr[i])] *= -1; 
    }
    return -1;
}

int main(){
    int arr[] = {0,7,2,5,4,0,1,3,6};
    cout << MissingNumber(arr, 9) << endl;
    return 0;
}