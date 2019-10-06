#include <iostream>
#include <cstring>
using namespace std;

void shift_string(char* s) {
    int i = 1;
    for(; s[i] != '\0'; i++){
        s[i-1] = s[i];
    }
    s[i-1] = '\0';
}

void removeConsecutiveDuplicates(char *input) {
    if(strlen(input) < 2) return;
    removeConsecutiveDuplicates(input + 1);
    if(input[0] == input[1]) 
        shift_string(input); 
}


int main(){
    char s[] = "aaaaabbbbaaaaaaaa";
    cout << s << endl;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
    return 0;
}