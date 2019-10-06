#include <iostream>
#include <string>
using namespace std;

string mapping(int i){
    switch(i){
        case 2: return "abc";
        case 3: return "def";
        case 4: return "ghi";
        case 5: return "jkl";
        case 6: return "mno";
        case 7: return "pqrs";
        case 8: return "tuv";
        case 9: return "wxyz";
        default: return "";
    }
}

void keypad(int n, string output) {
    if(n==0 || n==1){
        cout << output << endl;
        return;
    }
    string str = mapping(n%10);
    int str_s = str.length(); //str_size
    for(int i=0; i<str_s; i++) {
        keypad(n/10, str[i] + output);
    }
}

void printKeypad(int num){
    keypad(num, "");
}
