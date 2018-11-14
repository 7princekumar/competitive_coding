#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the count_strict_numbers function below.
long count_strict_numbers(int num_digits) {
    if(num_digits == 0){
        return 0;
    }else if(num_digits == 1){
        return 9;
    }else if(num_digits == 2){
        return 17;
    }else{
        int sum = 0;
        for(int i=3; i<num_digits; i++){
            sum += 2* (count_strict_numbers(num_digits-1));
        }
        return sum;
    }
    
}





int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string num_digits_temp;
    getline(cin, num_digits_temp);
    
    int num_digits = stoi(ltrim(rtrim(num_digits_temp)));
    
    long res = count_strict_numbers(num_digits);
    
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

