#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1000005
typedef pair<int, int> pii;

bool compare(pii a, pii b) {
    return a.second < b.second;
}

inline void print_apii(pii a[MAX], int n){
    for(int i=0; i<n; i++){
        cout << "(" << a[i].first << "," << a[i].second << ") ";
    }
    cout << endl;
}

#undef int
int main() {
#define int long long
    int n; cin >> n;
    pii a[MAX];
    for(int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+n, compare);
    //print_apii(a, n);
    int count = 1; //picked the first activity!
    int lpft = a[0].second; //last_picked_finish_time
    for(int i=1; i<n; i++) {
        if(a[i].first >= lpft) {
            lpft = a[i].second;
            count++;  
        }
    }
    cout << count << endl;
    return 0;
}