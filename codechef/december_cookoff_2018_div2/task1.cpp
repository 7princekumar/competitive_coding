#include <iostream>
#include <string>
#include <vector>
#include <cstdbool>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int D; cin>> D;
        int d, p;
        vector<int> di;
        vector<int> pi;
        while(D--){
            cin >> d >> p;
            di.push_back(d);
            pi.push_back(p);
        }
        int Q; cin >> Q;
        while(Q--){
            int deadline, req;
            cin >> deadline >> req;
            int sum = 0;
            int last = -1;
            for(int i=0; i< di.size() && di[i] <= deadline ; i++){
                last = i;
                sum += pi[i];
            }
            if(last == -1){
                cout << "Go Sleep" << endl;
            }else{
                continue;
            }
            if(sum >=  di[last]){
                cout << "Go Camp" << endl;
            }else{
                cout << "Go Sleep" << endl;
            }
        }
    }
    return 0;
}