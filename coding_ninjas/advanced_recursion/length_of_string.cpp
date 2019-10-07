#include<bits/stdc++.h>
using namespace std;

int length(string s){
    if(s.empty()) return 0;
    return 1 + length(s.substr(1));
}

int main(){
    string s = "hello";
    cout << length(s) << endl;
    return 0;
}