#include <map>
#include <cstring>
char* uniqueChar(char *str){
    char str_copy[50000];
    strcpy(str_copy, str);
    map<char,int> m;
    for(int i=0; str[i] != '\0'; i++) {
       m[str[i]]++;
    }
    str[0] = '\0';
    int str_s = 0;
    for(int i=0; str_copy[i] != '\0'; i++) {
        if(m[str_copy[i]]) {
            str[str_s] = str_copy[i];
            m[str_copy[i]] = 0;
            str_s++;
        }
    }
    str[str_s] = '\0';
    return str;
}