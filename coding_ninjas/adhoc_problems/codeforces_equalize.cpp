//link: https://codeforces.com/problemset/problem/1037/C
#include <bits/stdc++.h>
using namespace std;

int min_cost(string& a, string& b, int n) {
    int i=0, cost = 0;
    while(i < n) {
        if(a[i] != b[i]){
            if(i+1 < n && (a[i+1] != b[i+1]) && (a[i] == b[i+1])){
                // swapping! No need to swap though
                i+=2;
            }else{
                // flipping! No need to flip though [we just need the cost]
                i++;
            } 
            cost++;
        }else {
            i++;
        }
    }
    return cost;
}

int main() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    cout << min_cost(a, b, n) << endl;
    return 0;
}