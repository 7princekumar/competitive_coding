#include<bits/stdc++.h>
using namespace std;

inline void print_pair(int x, int n) {
    for(int i=0; i<n; i++) {
        cout << -1 * x << " " << x << endl;
    }
}

void PairSum(int *input, int n) {	 
    unordered_map<int, int> um;
    for(int i=0; i<n; i++) {
        um[input[i]]++;
        print_pair(abs(input[i]), um[-1 * input[i]]);
    }
}

int main() {
    int input[] = {2, 1, -2, 2, 3, 2, 2, -2};
    int size = sizeof(input)/sizeof(input[0]);
    PairSum(input, size);
}