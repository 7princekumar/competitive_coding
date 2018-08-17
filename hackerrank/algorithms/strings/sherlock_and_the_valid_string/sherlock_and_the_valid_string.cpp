#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map> //pairs
#include <unordered_set> //hash

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
typedef long long ll;
//int max= *max_element(v.begin(), v.end());

using namespace std;

void print_i_v(vector<int> &v){
    for(int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

// Complete the isValid function below.
string isValid(string s) {
    bool remove = false;
    vector<int> freq(26);
    
    for(int i=0 ; i<s.length(); i++){
        freq[s[i] - 97]++;
    }
    
    set<int> iset;
    for(int i=0; i<freq.size(); i++){
        if(freq[i] != 0){
            iset.insert(freq[i]);
        }
    }
    
    if(iset.size() < 2){
        return "YES";
    } else if(iset.size() > 2){
        return "NO";
    } else {
        set<int> :: iterator itr;
        
        itr = iset.begin();
        int first = *itr;
        int first_freq = 0;
        
        itr++;
        int second = *itr;
        int second_freq = 0;
        
        for(int i=0; i<freq.size(); i++){
            if(freq[i] == first){
                first_freq++;
            }
            if(freq[i] == second){
                second_freq++;
            }
        }
        
        if(first_freq == 1 || second_freq == 1){
            if(first == 1 || first == 1){
                if(first_freq > 1){
                    return "NO";
                }
                return "YES";
            } else {
                return "NO";
            }
        } else {
            return "NO";
        }
        
    }
    
    
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    //fout.close();

    return 0;
}
