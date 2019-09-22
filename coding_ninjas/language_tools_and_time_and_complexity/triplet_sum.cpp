// arr - input array
// size - size of array
// x - sum of triplets
#include <bits/stdc++.h>
#include <algorithm>

void print_unique(int a, int b, int c, unordered_set<string>& us){
    string temp = to_string(a) + " " + to_string(b) + " " + to_string(c);
    if(us.find(temp) == us.end()){
        us.insert(temp);
        cout << a << " " << b << " " << c << endl;
    } 
}

void print_all(int a, int b, int c){
    cout << a << " " << b << " " << c << endl;
}

// solved using double pointer technique in O(n2)
void FindTriplet(int arr[], int size, int x) {
    sort(arr, arr + size);
    for(int i=0; i<size-2; i++) {
        for(int j=i+1; j<size-1; j++) {
            for(int k=j+1; k<size; k++) {
                if(arr[i] + arr[j] + arr[k] == x){
                    print_all(arr[i], arr[j], arr[k]);
                }
            }
        }
    }
}
