#include <iostream>
#include <vector>
#include <cstdbool>
#include <unordered_set>
using namespace std;

int main(){ 
    unordered_set<int> s;
    unordered_set<int> :: iterator itr;
    int n = 1000;
    for(int i=3; i<n; i++){
        if(i%3 == 0 || i%5==0){
            s.insert(i);
        }
    }

    int sum = 0;
    for(itr = s.begin(); itr != s.end(); itr++){
        sum += *itr;
    }

    cout << sum << endl;
    return 0;
}