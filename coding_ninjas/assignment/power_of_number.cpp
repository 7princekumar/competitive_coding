#include <bits/stdc++.h>
using namespace std;

#define MAX 500

int multiply(int x, int res[MAX], int res_s) {  //593 * 4 => [3][9][5] * 5;
    int prod, carry = 0;
    for(int i=0; i<res_s; i++) {
        prod   = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod / 10;
    }
    while(carry){
        res[res_s++] = carry % 10;
        carry /= 10;
    }
    return res_s;
}

void print_power(int x, int n) {
    if(x == 0){
        if(n == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    if(n <= 0){
        cout << 1 << endl;
        return;
    }
    bool is_negative = (x < 0) ? true : false;
    x = abs(x);
    //convert x to array: 593 -> [3][9][5]
    int res[MAX];
    int res_s = 0;
    int temp = x;
    while(temp){
        res[res_s++] = temp % 10;
        temp /= 10;
    }

    //multiply x, n times [x * x * x * ... n times]
    for(int i=2; i<=n; i++){
        res_s = multiply(x, res, res_s);
    }
    
    //print
    if(is_negative) cout << '-';
    for(int i=res_s -1; i>=0; i--){
        cout << res[i];
    }
    cout << endl;
}

int main() {
    int x, n; cin >> x >> n;
    print_power(x, n);
    return 0;
}