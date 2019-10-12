#include <bits/stdc++.h>
using namespace std;

const int n = 10;
void print_sol(char a[n][n]){
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

vector<string> read_words(){
    vector<string> words;
    
    string full_string;
    cin >> full_string;
    stringstream ss(full_string);
    
    string s;
    while(getline(ss, s, ';')) words.push_back(s);
    return words;
}

bool is_valid_horizontal(char cross[n][n], string word, int r, int c){
    if(c + word.length() > n) return false;
    int k = 0; //k for word
    for(int i=c; i<n; i++) {
        if(cross[r][i] == '-' || cross[r][i] == word[k]){
            k++;
            if(k == word.length()) return true;
        }else{
            return false;
        }    
    }
    return false;
}
void place_horizontal(char cross[n][n], string word, vector<bool>& helper, int r, int c){
    int k = 0; //for word
    for(int i=c; i<c+word.length(); i++){
        if(cross[r][i] == '-') helper[k] = true;
        cross[r][i] = word[k++];
    }
}
void unplace_horizontal(char cross[n][n], string word, vector<bool>& helper, int r, int c){
    int k = 0; //for word
    for(int i=c; i<c+word.length(); i++){
        if(helper[k++] == true) cross[r][i] = '-';
    }
}
bool is_valid_vertical(char cross[n][n], string word, int r, int c){
    if(r + word.length() > n) return false;
    int k = 0; //k for word
    for(int i=r; i<n; i++) {
        if(cross[i][c] == '-' || cross[i][c] == word[k]){
            k++;
            if(k == word.length()) return true;
        }else{
            return false;
        }    
    }
    return false;
}
void place_vertical(char cross[n][n], string word, vector<bool>& helper, int r, int c){
    int k = 0; //for word
    for(int i=r; i<r+word.length(); i++){
        if(cross[i][c] == '-') helper[k] = true;
        cross[i][c] = word[k++];
    }
}
void unplace_vertical(char cross[n][n], string word, vector<bool>& helper, int r, int c){
    int k = 0; //for word
    for(int i=r; i<r+word.length(); i++){
        if(helper[k++] == true) cross[i][c] = '-';
    }
}

bool solve_crossword(char cross[n][n], vector<string>& words, int wi) { //wi - word_index
    if(wi == words.size()) return true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(is_valid_horizontal(cross, words[wi], i, j)){
                vector<bool> helper(words[wi].length());
                place_horizontal(cross, words[wi], helper, i, j);
                if(solve_crossword(cross, words, wi+1)) return true;
                unplace_horizontal(cross, words[wi], helper, i, j);
            }
            else if(is_valid_vertical(cross, words[wi], i, j)){
                vector<bool> helper(words[wi].length());
                place_vertical(cross, words[wi], helper, i, j);
                if(solve_crossword(cross, words, wi+1)) return true;
                unplace_vertical(cross, words[wi], helper, i, j);
            }
        }
    }
    return false;
}

int main() {
    char cross[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> cross[i][j];
    vector<string> words = read_words();
    if(solve_crossword(cross, words, 0)) print_sol(cross);

    return 0;
}

/* 
Input:

+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

*/

/*
Output:
+ C + + + + + + + + 
+ A + + T + + + + + 
+ N I G E R I A + + 
+ A + + L + + + + + 
+ D + + A + + + + + 
+ A + + V + + + + + 
+ + + + I + + + + + 
+ + + + V + + + + + 
+ + + + + + + + + + 
C A L I F O R N I A 
*/