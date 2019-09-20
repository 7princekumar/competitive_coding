#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> arrival;
    vector<int> departure;
    int ele;
    for(int i=0; i<n; i++) {
        cin >> ele;
        arrival.push_back(ele);
    }
    for(int i=0; i<n; i++) {
        cin >> ele;
        departure.push_back(ele);
    }
    int a[2400] = {0};
    //memset(a, 0, n*sizeof(a[0]));
    for(int i=0; i<n; i++) {
        a[arrival[i]]++;
        a[departure[i]]--;
    }
    int ans = 0;
    int sum = 0;
    for(int i=0; i<2400; i++) {
        sum += a[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    
    
    
    return 0;
}