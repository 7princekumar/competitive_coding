#include<bits/stdc++.h>
using namespace std;

int subs(string s, string* output) {
    if(s.empty()){
        output[0] = "";
        return 1;
    }
    int smallerOutputSize = subs(s.substr(1), output);
    for(int i=0; i<smallerOutputSize; i++) {
        output[smallerOutputSize + i] = s[0] + output[i];
    }
    return 2 * smallerOutputSize;
}

int main() {
    string s = "abc";
    int n = pow(2, s.length());
    string* output = new string[n];
    int size = subs(s, output);
    for(int i=0; i<size; i++){
        cout << output[i] << endl;
    }
    delete[] output;
    output = NULL;
    return 0;
}