//https://www.codechef.com/ZCOPRAC/problems/ZCO15002
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, k; cin >> n >> k;
    ll* a = new ll[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    ll i=0, j=1, vcount = 0;
    if(n > 1){
        while(j < n){
            if(a[j] - a[i] >= k){
                vcount += n - j;
                i++;
                if(i == j) j++;
            }else{
                j++;
            }
        }
    }
    cout << vcount << endl;

    delete[] a;
    a = NULL;
    return 0;
}