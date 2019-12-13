#include<bits/stdc++.h>
using namespace std;

#define MAX 1005

int main() {
    int s, d;
    cin >> s >> d;
    s -= 1;
    int ans[MAX];
    for(int i=d-1; i>0; i--) {
        if(s >= 9) {
            ans[i] = 9;
            s -= 9;
        }else{
            ans[i] = s;
            s = 0;
        }    
    }
    ans[0] = s + 1;
    for(int i=0; i<d; i++) {
        cout << ans[i];
    }
    cout << endl;
}