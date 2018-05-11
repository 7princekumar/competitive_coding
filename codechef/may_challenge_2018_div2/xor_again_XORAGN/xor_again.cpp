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
        vector<int> seqA = elements;
        vector<int> seqB;
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                seqB.push_back(seqA[j] + seqA[k]);
            }
        }

        int result = seqB[0];
        for(int j=1; j<seqB.size(); j++){
            result = result ^ seqB[j];
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