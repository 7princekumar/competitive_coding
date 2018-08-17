#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map> //pairs
#include <unordered_set> //hash

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
//int max= *max_element(v.begin(), v.end());

using namespace std;

void print_i_v(vector<string> &v){
    for(int j=0; j<v.size(); j++){
        cout<<v[j]<< endl;
    }
    cout<<endl;
}







int main() {
    int T; //test cases
    //cin >> T;
    T = 1;
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        int N;
        cin >> N;

        //get the list of elements
        vector<string > colors;
        colors.clear();
        for (int j = 0; j < N; j++){
            string ele;
            cin >> ele;
            colors.push_back(ele);
        }

        string stones_colors[] = {"purple", "green", "blue", "orange", "red", "yellow"};
        string stones_powers[] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};

        vector<string> remaining_powers;
        vector<string> remaining_powers2;
        
        for(int j=0; j<N; j++){
            for(int k=0; k<6; k++){
                if(colors[j] == stones_colors[k]){
                    remaining_powers.push_back(stones_powers[k]);
                }
            }
        }

        for(int j=0; j<6; j++){
            int found = 0;
            for(int k=0; k<remaining_powers.size(); k++){
                if(stones_powers[j] == remaining_powers[k]){
                    found = 1;
                }
            }
            if(found == 0){
                remaining_powers2.push_back(stones_powers[j]);
            }
        }

        
        cout<<remaining_powers2.size()<< endl;
        print_i_v(remaining_powers2);





    } //for each test case

    // //print results
    // for (int i = 0; i < results.size(); i++){
    //     cout << results[i] << endl;
    // }

    return 0;
}

//