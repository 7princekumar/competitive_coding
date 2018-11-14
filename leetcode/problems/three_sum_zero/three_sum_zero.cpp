#include <iostream>
#include <cstdbool>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> make_vec(int a, int b, int c){
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    return v;
}

vector<vector<int> > three_sum(vector<int>& nums) {
    vector<vector<int> >results;
    if(nums.size() < 2) return results;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()- 2; i++){                             
        int a = nums[i];
        if(a > 0) break; //if first element of set is greater than zero, sum can never be zero
        if(i>0 && a == nums[i-1]) continue; //if first element is equal to previous ele in array, skip it
        
        int j = i + 1;           
        int k = nums.size() - 1; 
        while(j < k){
            int b = nums[j];
            int c = nums[k];
            int value = a+b+c;
            if(value == 0){ //check if other sets are possible using the same starting ele(a)
                results.push_back(make_vec(a,b,c));
                while(b == nums[++j]); //skip same b's
                while(c == nums[--k]); //skip same c's
            }else if(value > 0){
                k--;
            }else{
                j++;
            }
        }
        
    }
    
    return results;
}

void print_i_2v(vector<vector<int> >& v){
    for(int i=0; i<v.size(); i++){
        cout <<"Set "<<i+1 <<": ";
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int a[] = {-1,-1,0,1,2,9,3,-4};
    int a_size = sizeof(a)/sizeof(a[0]);
    vector<int> v(begin(a), end(a));
    vector<vector<int> > results = three_sum(v);
    print_i_2v(results);
    return 0;
}