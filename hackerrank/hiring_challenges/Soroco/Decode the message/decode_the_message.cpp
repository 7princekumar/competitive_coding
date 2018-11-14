#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the kth_char_in_message function below.
char kth_char_in_message(string emsg, int k) {
    string msg="", temp="";
    for(int i=0; i<emsg.length(); i++){
        if(!isdigit(emsg[i])){
            temp.push_back(emsg[i]);
        }else{
            for(int j=0; j< int(emsg[i]-'0'); j++){
                msg += temp;
            }
            temp.clear();
        }
    }
    return msg[k-1];
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string encoded_message;
    getline(cin, encoded_message);
    
    string k_temp;
    getline(cin, k_temp);
    
    int k = stoi(ltrim(rtrim(k_temp)));
    
    char res = kth_char_in_message(encoded_message, k);
    
    fout << res << "\n";
    
    fout.close();
    
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    
    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
            );
    
    return s;
}

string rtrim(const string &str) {
    string s(str);
    
    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
            );
    
    return s;
}

