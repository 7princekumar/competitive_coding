#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
//int max= *max_element(v.begin(), v.end());

using namespace std;

void print_i_v(vector<int> &v){
    for(int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

string highestValuePalindrome(string s, int n, int k) {
    unsigned long long int mis_match = 0;
    unsigned long long int i = 0;
    unsigned long long int j = n-1;
    
    while(i < j){
        if(s[i] != s[j]){
            mis_match++;
        }
        i++;
        j--;
    }
    
    i= 0; j= n-1;

    if (k < mis_match){
        return to_string(-1);
    } 

    while(i<j){
        // cout<<"s: "<<s<< endl;
        if(s[i] != s[j]){
            if( k == mis_match){
                int max_ele = max(s[i], s[j]);
                if(max_ele == s[i]){
                    s[j] = s[i];
                } else {
                    s[i] = s[j];
                } 
                k--;
                mis_match--;
            } else if(k >= mis_match+1){
                if(s[i] == '9' || s[j] == '9'){
                    if(s[i] == '9'){
                        s[j] = '9';
                    } else {
                        s[i] = '9';
                    }
                    k--;      
                } else {
                    s[i] = '9';
                    s[j] = '9';
                    k -= 2;
                }
                mis_match--;
            }


            
        }
        i++; 
        j--;
    }

    //cout<<"K: "<<k<< endl; //check
    i = 0; j = n-1;
    while((k >=2) && (i<j)){
        if(s[i] != '9'){
            s[i] = '9';
            s[j] = '9';
            k -= 2;
        }
        i++; j--;
    }
    
    if((s.length()%2==1) && (k>0)){
        if(s[s.length()/2] != '9'){
            s[s.length()/2] = '9';
            k--; 
        }
    }

    cout<<"k: "<<k<<endl;
    cout<<"mis_match: "<<mis_match<<endl;
    
    
    return s;
}


int main()
{
    //cout<< highestValuePalindrome("3943", 4, 1)<<endl; //correct
    //cout<< highestValuePalindrome("092282", 6, 3)<<endl; //correct
    //cout<< highestValuePalindrome("932239", 6, 2)<<endl; //correct
    //cout<< highestValuePalindrome("11119111", 8, 4)<<endl; //correct
    cout<< highestValuePalindrome("11119111", 8, 2)<<endl; //correct
    //cout<< highestValuePalindrome("329", 3, 2)<<endl; 
    //cout<< highestValuePalindrome("1111111", 7, 1)<<endl; 
    // cout<< highestValuePalindrome("9711319", 7, 4)<<endl; 
    

    return 0;
}