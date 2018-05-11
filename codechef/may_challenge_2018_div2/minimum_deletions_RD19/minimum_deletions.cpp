#include <iostream>
#include <algorithm>
#include <vector>

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort

//Title: Minimum Deletions. [CodeChef May Challenge 2018 Div2] [RD19]
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(vector<int> arr, int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}

int main() {
    int T; //test cases
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        int N;
        cin >> N; //N int for each test-case

        //get the list of elements
        vector<int> elements;
        elements.clear();
        for (int j = 0; j < N; j++) {
            int ele;
            cin >> ele;
            elements.push_back(ele);
        }

        //check
        int result = findGCD(elements, N);
        if(result == 1){
            results.push_back(0);
        }else{
            results.push_back(-1);
        }

    } //for each test case

    //print results
    for (int i=0; i< results.size(); i++) {
        cout<<results[i]<<endl;
    }



    return 0;
}

//