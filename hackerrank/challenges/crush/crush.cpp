//LINK: https://www.hackerrank.com/challenges/crush/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
/////BRUTE FORCE
// long arrayManipulation(int n, vector<vector<int>> queries) {
//     vector<long long> v;
//     v.resize(n);
    
//     for(int i=0; i<queries.size(); i++){
//         for(int j=queries[i][0] -1 ; j<queries[i][1]; j++){
//             v[j] += queries[i][2];
//         }
//     }
    
//     return *max_element(v.begin(), v.end());
// }

long arrayManipulation(int n, vector<vector<int> > queries) {
    vector<long> v;
    v.resize(n+1); //n - number of elements in the array
    long N = queries.size(); //number of a,b,k sequence
    long a, b, k;
    
    for(long i=0; i<N; i++){
        a = queries[i][0]-1;
        b = queries[i][1]-1;
        k = queries[i][2];
        
        v[a] += k; //mountain increases by k
        v[b+1] -= k; //mountain decreases by k
    }
    
    //get the actual v
    for(int i=1; i<n; i++){
        v[i] += v[i-1]; 
    }
    
    return *max_element(v.begin(), v.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
