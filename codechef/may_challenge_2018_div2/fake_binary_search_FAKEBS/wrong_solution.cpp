#include <iostream>
#include <vector>
#include <algorithm>

//Title:Fake Binary Search [FAKEBS]
using namespace std;

int main() {
    int T; //test cases
    cin >> T;
    int N, Q;
    vector< vector<int> > results;

    for (int i = 1; i < T+1; i++) {
        cin >> N >> Q;

        //get the list of elements
        vector<int> elements;
        elements.clear();
        for (int j = 0; j < N; j++){
            int ele;
            cin >> ele;
            elements.push_back(ele);
        }

        //get the list of X
        vector<int> x_array;
        x_array.clear();
        for (int j = 0; j < Q; j++){
            int ele;
            cin >> ele;
            x_array.push_back(ele);
        }
        

        //----write from here-----
        vector<int> local_results;
        for(int j=0; j< Q; j++){ //for each x
            //store x
            int x = x_array[j];
            //find position of x in original array
            vector<int>::iterator it;
            it = find(elements.begin(), elements.end(), x);
            int x_pos = distance(elements.begin(), it);

            vector<int> elements2 = elements;
            //if(fake_binary_search(elements, N, x) )
            int low, high, mid, result = 0;
            low = 0;
            high = N-1;
            while(low <= high){
                mid = (low + high)/2;
                
                if(x == elements2[mid]){
                    break;
                } else if(x < elements2[mid]){ //ideally, move left
                    if(x_pos > mid){
                        //swap using left-number , now move right
                        //find left-number
                        int temp_pos = mid;
                        for(int k=mid -1; k>=0; k--){
                            if(elements2[k] < x){
                                temp_pos = k;
                            }
                        }
                        swap(elements2[mid], elements2[temp_pos]);
                        low = mid + 1; //move right
                        result++;
                    } else {
                        //no swap, continue to left
                        high = mid - 1;
                    } 
                } else { //ideally, move right
                    if(x_pos < mid){
                        //swap using right-number, now move left
                        //find right-number
                        int temp_pos2 = mid;
                        for(int k=mid +1; k<N; k++){
                            if(elements2[k] > x){
                                temp_pos2 = k;
                            }
                        }
                        swap(elements2[mid], elements2[temp_pos2]);
                        high = mid - 1; //move left
                        result++;
                    } else {
                        //no swap, continue to right
                         low = mid + 1;
                    }  
                }// END of if-else
            } //while
            local_results.push_back(result);
            elements2.clear();
        }
        results.push_back(local_results);
        local_results.clear();



    } //for each test case

    //print results
    for (int i = 0; i < results.size(); i++){
        for(int j=0; j < Q; j++){
            cout << results[i][j] << endl; 
        }
        
    }

    return 0;
}