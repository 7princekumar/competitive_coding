#include<bits/stdc++.h>
using namespace std;

inline int min(int a, int b){
    return (a < b) ? a : b;
}

int minAbsoluteDiff(int arr[], int n) {
    sort(arr, arr+n);
    int m = INT_MAX;
    for(int i=0; i<n-1; i++) {
        m = min(m, arr[i+1] - arr[i]);
    }
    return m;
}