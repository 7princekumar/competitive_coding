#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

void swapit(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

bool is_possible(int* a, int n) {
    for(int i=0; i<n-1; i++) {
        if(a[i+1] == a[i] - 1){
            swapit(&a[i+1], &a[i]);
        }
    }
    bool is_sorted = true;
    for(int i=0; i<n-1; i++) {
        if(a[i+1] < a[i]){
            is_sorted = false;
            break;
        }
    }
    return is_sorted;
}


int main(){
    int tc; cin >> tc;
    while(tc-- ){
        int n; cin >> n;
        int a[MAX];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        if(is_possible(a, n)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    

    return 0;
}