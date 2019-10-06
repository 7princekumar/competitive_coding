#include <bits/stdc++.h>
#include <cstring>
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

int keypad(int num, string output[]){
    if(num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    
    int smallerOutputSize = keypad(num / 10, output); //smallerOutputSize
    string str = mapping(num%10);
    int str_s = str.length(); //str_size
    
    //copy old output str_s - 1 extra times
    for(int count=1; count<str_s; count++) {
        for(int i = 0; i<smallerOutputSize; i++) {
            output[count*smallerOutputSize + i] = output[i];
        } 
    }
    
    //attach
    for(int count=0; count<str_s; count++) {
        for(int i = 0; i<smallerOutputSize; i++) {
            output[count*smallerOutputSize + i] += str[count];
        } 
    }
    return smallerOutputSize * str_s;
}
