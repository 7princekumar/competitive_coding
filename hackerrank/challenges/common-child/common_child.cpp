//LINK: https://www.hackerrank.com/challenges/common-child/
#include <bits/stdc++.h>
#define MAX 5001
using namespace std;

// Complete the commonChild function below.
//LONGEST COMMON SUBSEQUENCE
int lcs_len(string s1, int i, string s2, int j){
    if((i==s1.length()) || (j==s2.length())){
        return 0;
    }else{
        if(s1[i] == s2[j]){
            return 1 + lcs_len(s1, i+1, s2, j+1);
        }else{
            return max(lcs_len(s1, i+1, s2, j), lcs_len(s1, i, s2, j+1));
        }
    }
}

int lcs_len_dp(string s1, string s2, vector<vector<int> >& dp){
    for(int i=1; i<=s1.length()+1; i++){
        for(int j=1; j<=s2.length()+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[s1.length()][s2.length()];
}

int commonChild(string s1, string s2) {
    vector<vector<int> > dp;
    dp.resize(s1.length() + s2.length());
    for(int i=0; i<dp.size(); i++){
        dp[i].resize(s1.length() + s2.length());
    }
    return lcs_len_dp(s1, s2, dp);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
