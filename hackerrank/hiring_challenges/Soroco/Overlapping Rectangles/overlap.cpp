#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the calculate_area function below.
int calculate_area(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    return abs(max(x1, x3) - min(x2, x4)) * abs(min(y1, y3) - max(y2, y4));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string x1_temp;
    getline(cin, x1_temp);
    
    int x1 = stoi(ltrim(rtrim(x1_temp)));
    
    string y1_temp;
    getline(cin, y1_temp);
    
    int y1 = stoi(ltrim(rtrim(y1_temp)));
    
    string x2_temp;
    getline(cin, x2_temp);
    
    int x2 = stoi(ltrim(rtrim(x2_temp)));
    
    string y2_temp;
    getline(cin, y2_temp);
    
    int y2 = stoi(ltrim(rtrim(y2_temp)));
    
    string x3_temp;
    getline(cin, x3_temp);
    
    int x3 = stoi(ltrim(rtrim(x3_temp)));
    
    string y3_temp;
    getline(cin, y3_temp);
    
    int y3 = stoi(ltrim(rtrim(y3_temp)));
    
    string x4_temp;
    getline(cin, x4_temp);
    
    int x4 = stoi(ltrim(rtrim(x4_temp)));
    
    string y4_temp;
    getline(cin, y4_temp);
    
    int y4 = stoi(ltrim(rtrim(y4_temp)));
    
    int res = calculate_area(x1, y1, x2, y2, x3, y3, x4, y4);
    
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
