#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdbool>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w",  stderr);
#endif
    int tc;
    cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int max_score = 0;
        vector<int> a;
        int ele;
        for(int i=0; i<n; i++) {
            cin >> ele;
            a.push_back(ele * 20);
        }
        for(int i=0; i<n; i++) {
            cin >> ele;
            max_score = max(a[i] - 10*ele, max_score);
        }
        cout << max_score << endl;
    }
    return 0;
}