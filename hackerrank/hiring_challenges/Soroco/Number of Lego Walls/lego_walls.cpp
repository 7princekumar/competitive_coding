#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the numberOfWalls function below.
int numberOfWalls(vector<string> board) {
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string board_count_temp;
    getline(cin, board_count_temp);
    
    int board_count = stoi(ltrim(rtrim(board_count_temp)));
    
    vector<string> board(board_count);
    
    for (int i = 0; i < board_count; i++) {
        string board_item;
        getline(cin, board_item);
        
        board[i] = board_item;
    }
    
    int res = numberOfWalls(board);
    
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

