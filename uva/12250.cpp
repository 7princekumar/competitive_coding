#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;


string check_lang(string s){
  if(s == "HELLO")        return "ENGLISH";
  if(s == "HOLA")         return "SPANISH";
  if(s == "HALLO")        return "GERMAN";
  if(s == "BONJOUR")      return "FRENCH";
  if(s == "CIAO")         return "ITALIAN";
  if(s == "ZDRAVSTVUJTE") return "RUSSIAN";
  exit(0);
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
  #endif

  string s;
  int count = 1;
  while(getline(cin, s), s!= "#") {
    cout << "Case " << count++ << ": " << check_lang(s) << endl;
  }
  
  return 0;
}