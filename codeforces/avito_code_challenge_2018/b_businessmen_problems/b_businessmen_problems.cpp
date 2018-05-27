#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

typedef long long ll;
#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
//int max= *max_element(v.begin(), v.end());

using namespace std;

void print_i_v(vector<ll> &v){
    for(ll j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}







int main() {
    int T; //test cases
    T= 1;
    vector<ll> results;

    for (int i = 1; i < T+1; i++) {
        ll n, m;
        vector<ll> elements1;
        vector<ll> elements2;
        unordered_map <ll,ll> e_profit1; 
        unordered_map <ll,ll> e_profit2; 
        
        ll ele, profit, total_profit = 0;
        cin>>n;
        for(ll i=0; i<n; i++){
            cin>>ele;
            elements1.push_back(ele);
            cin>>profit;
            e_profit1.insert(make_pair(ele,profit));  
        }

        cin>>m;
        for(ll i=0; i<m; i++){
            cin>>ele;
            elements2.push_back(ele);
            cin>>profit;
            e_profit2.insert(make_pair(ele,profit));  
        }

        SORT(elements1, n);
        SORT(elements2, m);

        vector<ll> v_inter;                                       
        set_intersection (elements1.begin(), elements1.end(), elements2.begin(), elements2.end(), back_inserter(v_inter));                                           
       
        vector<ll> v_diff1;                    
        vector<ll> v_diff2;        
        set_difference (elements1.begin(), elements1.end(), v_inter.begin(), v_inter.end(), back_inserter(v_diff1));                                           
        set_difference (elements2.begin(), elements2.end(), v_inter.begin(), v_inter.end(), back_inserter(v_diff2));                                           
        
        for(ll j=0; j<v_diff1.size(); j++){
            total_profit += e_profit1[ v_diff1[j] ];
        }
        for(ll j=0; j<v_diff2.size(); j++){
            total_profit += e_profit2[ v_diff2[j] ];
        }
        // cout<<"tp before inter: "<<total_profit<<endl;

        for(ll j=0; j<v_inter.size(); j++){
            total_profit += max( e_profit1[ v_inter[j] ] ,  e_profit2[ v_inter[j] ] );
            // cout<<"max: "<<max( e_profit1[ v_inter[j] ] ,  e_profit2[ v_inter[j] ] )<<endl;
        }

        // cout<<"tp after inter: "<<total_profit<<endl;
        results.push_back(total_profit);
        
    } //for each test case

    //print results
    for (ll i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//