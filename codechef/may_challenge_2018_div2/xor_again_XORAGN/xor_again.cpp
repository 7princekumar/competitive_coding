#include <iostream>
#include <vector>

//Title:XOR Again [CodeChef May Challenge 2018 Div2][XORAGN]
using namespace std;

int main()
{
    int T; //test cases
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T + 1; i++)
    {
        int N;
        cin >> N;

        //get the list of elements
        vector<int> elements;
        elements.clear();
        for (int j = 0; j < N; j++)
        {
            int ele;
            cin >> ele;
            elements.push_back(ele);
        }

        //----write from here-----
        int result = elements[0] * 2;
        for(int j=1; j<N; j++){
            int temp = elements[j] * 2;
            result = result ^ temp;
        }
        
        results.push_back(result);
    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//