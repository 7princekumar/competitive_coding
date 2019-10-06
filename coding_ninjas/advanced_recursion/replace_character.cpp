#include <iostream>
using namespace std;

void replaceCharacter(char s[], char c1, char c2) {
    //base
    if(s[0] == '\0') return;
    //small calc
    if(s[0] == c1) s[0] = c2;
    //recursive call
    return replaceCharacter(s + 1, c1, c2);
}

int main(){
    char s[] = "hello";
    char c1 = 'l';
    char c2 = 'x';
    cout << s << endl;
    replaceCharacter(s, c1, c2);
    cout << s << endl;
    return 0;
}