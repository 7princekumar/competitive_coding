#include <iostream>
#include <vector>
#include <cstdbool>
using namespace std;

int main(){
    int T; cin >> T;
    vector<int> results;
    while(T--){
        int N; cin >> N;
        vector<int> A; int ele;
        for(int i=0; i<N; i++){
            cin >> ele; A.push_back(ele);
        }

        bool found = false;
        for(int i=0; i<N && !found; i++){
            for(int j=1; j<N && !found; j++){
                int a = A[i];
                int b = A[j];
                 if((i != j) && (a != b) && (A[a] == A[b])){
                    found = true;
                    results.push_back(1);
                }
            }  
        }
        if(!found){
            results.push_back(0);
        }
    }

    for(int i=0; i<results.size(); i++){
        if(results[i] == 1){
            cout << "Truly Happy" << endl;
        }else{
            cout << "Poor Chef" << endl;
        }
    }

    return 0;
}