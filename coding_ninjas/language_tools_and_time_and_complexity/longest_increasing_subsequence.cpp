#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 2

void go_forward(int curr_ele, int& curr_len, unordered_map<int, int>& um){
    bool done = false;
    while(!done){
        curr_ele++;
        if(um[curr_ele] && um[curr_ele] == UNVISITED){
            curr_len++;
            um[curr_ele] = VISITED;
        }else{
            done = true;
        }
    }
}


int go_backward(int curr_ele, int& curr_len, unordered_map<int, int>& um){
    bool done = false;
    while(!done){
        curr_ele--;
        if(um[curr_ele] && um[curr_ele] == UNVISITED){
            curr_len++;
            um[curr_ele] = VISITED;
        }else{
            done = true;
            curr_ele++; //because we need to return proper curr_ele
        }
    }
    return curr_ele;
}


vector<int> longestSubsequence(int *arr, int n){
    int max_len = 1;
    int start_ele = arr[0];
    unordered_map<int, int> um;
    for(int i=0; i<n; i++) {
        um[arr[i]] = UNVISITED; 
    }
    for(int i=0; i<n; i++) {
        int curr_len = 1;
        int curr_ele = arr[i];
        if(um[curr_ele] == UNVISITED){
            um[curr_ele] = VISITED;
            go_forward(curr_ele, curr_len, um);
            curr_ele = go_backward(curr_ele, curr_len, um);
        }
        if(curr_len > max_len) {
            max_len = curr_len;
            start_ele = curr_ele;
        }
    }
    vector<int> ans;
    for(int i=0; i<max_len; i++) {
        ans.push_back(start_ele + i);
    }
    return ans;
}

void print_vi(vector<int>& v){
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    int input[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    int size = sizeof(input)/sizeof(input[0]);
    vector<int> ans = longestSubsequence(input, size);
    print_vi(ans);
}