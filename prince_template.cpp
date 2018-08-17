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
//#include <utility> //for pair
// #define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
// int max= *max_element(v.begin(), v.end());
// #define MOD 1000000007

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

/*

cout<<"PRINT VECTOR: ";
for(int j=0; j<elements.size(); j++){
    cout<<elements[j]<<" ";
}
cout<<endl;


//Position of element in a vector
vector<int>::iterator it;
it = find(elements.begin(), elements.end(), element);
int pos = distance(elements.begin(), it);


//Modulo rules
(a+b)%m = (a%m+b%m)%m.
(a*b)%m = (a%m*b%m)%m.


//convert array to vector
int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
int n = sizeof(arr)/sizeof(arr[0]);
vector<int> vect(arr, arr+n);


//HASH 
map<int, vector<int> > hash;
hash[0].push_back(1);
hash[0].push_back(2);
hash[0].push_back(3);




//other
template<typename ForwardIterator, typename T>
ForwardIterator first_less_than (ForwardIterator first, ForwardIterator last, T value) {
	auto it = std::lower_bound (first, last, value);
	return (it == first ? last : --it);
}

auto it  = first_less_than (v.begin (), v.end (), 3);
cout << (it  != v.end () ? to_string (*it)  : "Not Found") << endl; // outputs 1
cout << distance (v.begin (), it) << endl; // outputs 1
*/