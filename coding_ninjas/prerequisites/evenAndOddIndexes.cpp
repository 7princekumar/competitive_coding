#include<bits/stdc++.h>
using namespace std;

#define N 100005

int get_esum(int* a, int n){
    int esum = 0;
    for(int i=0; i<n; i++){
        if(i%2 == 0 && a[i]%2 == 0) esum += a[i];
    }
    return esum;
}

int get_osum(int* a, int n){
    int osum = 0;
    for(int i=0; i<n; i++){
        if(i%2 != 0 && a[i]%2 != 0) osum += a[i];
    }
    return osum;
}

int main()
{
    int n;
    cin >> n;
    int a[N];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    cout << get_esum(a, n) << " " << get_osum(a, n) << endl;
    
	return 0;
}
