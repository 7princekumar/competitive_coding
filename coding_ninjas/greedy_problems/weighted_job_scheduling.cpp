#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005

struct item{
    int start;
    int finish;
    int profit;
};

bool compare(struct item a, struct item b) {
    return a.finish < b.finish;
}

int bs(struct item a[MAX], int startp, int endp, int ele) {
    int ans = -1, midp; 
    while(startp <= endp) {
        midp = startp + (endp - startp)/2;
        if(ele >= a[midp].finish) {
            ans = midp;
            startp = midp + 1;
        }else{
            endp = midp - 1;
        }
    }
    return ans;
}

int get_pos(struct item a[MAX], int i, int i_start) {
    return bs(a, 0, i, i_start); //binary_search
}

int main() {
    int n; cin >> n;
    struct item a[MAX];
    for(int i=0; i<n; i++) {
        cin >> a[i].start >> a[i].finish >> a[i].profit;
    }
    sort(a, a+n, compare);

    int dp[MAX];
    dp[0] = a[0].profit;
    int include = 0, exclude = 0;
    for(int i=1; i<n; i++) {
        exclude = dp[i-1];
        int pos = get_pos(a, i, a[i].start);
        include = a[i].profit;
        if(pos > -1) include += dp[pos];
        dp[i] = max(exclude, include);
    }
    cout << dp[n-1] << endl;

    return 0;
}