#include <bits/stdc++.h>
using namespace std;

void shift_left(char* s){
    int i;
    for(i=1; s[i] != '\0'; i++) {
        s[i-1] = s[i];
    }
    s[i-1] = s[i];
}

void remove_x(char* s){
    if(s[0] == '\0') return;
    if(s[0] == 'x' || s[0] == 'X'){
        shift_left(s);
        remove_x(s);
    }else{
        remove_x(s + 1);
    }
}

int main(){
    char s[] = "helxxlxo";
    cout << s << endl;
    remove_x(s);
    cout << s << endl;
    return 0;
}