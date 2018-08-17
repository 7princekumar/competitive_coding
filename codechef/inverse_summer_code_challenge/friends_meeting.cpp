#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
typedef long long ll;
//int max= *max_element(v.begin(), v.end());


void print_i_v(vector<int> &v){
    for(unsigned int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

bool is_prime(int n){
    if(n<=1) return false;
    if(n==2) return true;
    for(int i=3; i<n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}





int main() {
    int T; //test cases
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        int N;
        cin >> N;

        //get the list of elements
        vector<int> elements;
        elements.clear();
        for (int j = 0; j < N; j++){
            int ele;
            cin >> ele;
            elements.push_back(ele);
        }

        //----write from here-----
        int ans;
        //check for 1 and its position
        int pos_one = -1;
        for(int i=0; (i<N) && (pos_one == -1); i++){
            if(elements[i] == 1){
                pos_one = i;
                // cout<<"\n1 Pos[L61]: "<<pos_one<<endl;
            }
        }
        if(pos_one == -1){
            ans = -1;
        }else{
            int smallest_prime = INT_MAX;
            for(int i = 0; i<N; i++){
                if(is_prime(elements[i])){
                    // cout<<"Prime[L70]: "<<elements[i]<<endl;
                    if(elements[i] < smallest_prime){
                        smallest_prime = elements[i];
                    }
                }
            }
            if(smallest_prime == 1 || smallest_prime == INT_MAX){
                ans = -1;
            }else{
                ans = smallest_prime;
            }
        }

        results.push_back(ans);



    } //for each test case

    //print results
    for (unsigned int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//