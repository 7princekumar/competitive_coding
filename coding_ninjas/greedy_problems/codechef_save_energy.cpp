#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100005

int main() {
    #define int long
    int n; cin >> n;
    int a[MAX];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int i = 0, j;
    while(i < n-1) {
        j = i+1;
        while(j < n-1) {
            if(abs(a[j]) < abs(a[i]) || ((abs(a[j])==abs(a[i])) && a[i] > 0)){
                break;
            }
            j++;
        }
        ans += (j-i)*a[i] + (j*j - i*i)*a[i]*a[i] ;
        i = j;
    }
    cout << ans;

    return 0;
}
