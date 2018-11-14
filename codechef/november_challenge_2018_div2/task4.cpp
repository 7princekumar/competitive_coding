#include <iostream>
#include <vector>
#include <list>
#include <cstdbool>
#include <algorithm> //max
using namespace std;
#define int long long

void rotate_right_list(list<int>& l){
    l.push_front(l.back());
    l.pop_back();
}

int lcs_len(list<int>& s, int k, int n){
    list<int>:: iterator itr;
    int g = 0;
    int l = 0;
    for(itr= s.begin(); itr != s.end(); itr++){
        if(*itr == 1){
            l++;
            g = max(g, l);
            if(g >= k) return k;
        }else{
            l = 0;
            g = max(g, l);
            if(g >= k) return k;
        }
    }
    return g;
}

#undef int
int main(){
#define int long long
    int n, q, k; cin >> n >> q >> k;
    
    list<int> s; int ele;
    for(int i=0; i<n; i++){
        cin >> ele; s.push_back(ele);
    }

    char query;

    for(int i=0; i<q; i++){
        cin >> query;
        if(query == '!'){
            rotate_right_list(s);
        }else{
            cout << lcs_len(s,k,n) << endl;
        }
    }


    return 0;
}