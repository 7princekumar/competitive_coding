#include <iostream>
#include <vector>
// #include <algorithm>
// #include <math.h>
// #include <ctype.h>
// #include <set>
// #include <stack>
// #include <queue>
// #include <deque>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <string>
// #define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort

//Title: [CODE: ]
using namespace std;



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





    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//