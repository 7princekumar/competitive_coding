#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int ele;
    for(int i=0; i<n; i++){
        cin >> ele;
        if(ele == 1){
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";
    return 0;
}

//