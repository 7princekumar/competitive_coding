#include <iostream>
#include <vector>
#include <algorithm>

#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort
#define MOD 1000000007
//int max= *max_element(v.begin(), v.end());

using namespace std;

void print_i_v(vector<int> &v){
    for(int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}







int main() {
    int T; //test cases
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T+1; i++) {
        int N;
        cin >> N;

        //get the list of elements
        int ele;
        vector<vector<int> > elements;
        elements.resize(N);
        //int elements[N][2*N - 1];
        for (int j = 0; j < N; j++){
            for(int k=0; k < (2*N) -1 - j; k++){
                if(k < N-1-j){
                    //elements[j][k] = 0;
                    elements[j].push_back(0);
                } else {
                    cin>> ele;
                    //elements[j][k] = ele;
                    elements[j].push_back(ele);
                }
            }
            //print_i_v(elements[j]);
            int ele_size = elements[j].size();
            //cout<<"size: "<<ele_size<<endl ;
            while(ele_size < (2*N)-1){
                elements[j].push_back(0);
                ele_size++;
                //cout<<ele_size<<endl ;
            }
            //cout<<"Array: ";
            //print_i_v(elements[j]);
        }

        //----write from here-----
        int max_sum = 0;
        
        for(int j=0; j<2*N -1; j++){
            int temp_sum = 0;
            for(int k=0; k<N; k++){
                temp_sum += elements[k][j];
            }
            if(temp_sum > max_sum){
                max_sum = temp_sum;
            }
        }

        results.push_back(max_sum);

    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//