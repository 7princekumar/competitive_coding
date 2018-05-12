#include <iostream>
#include <vector>
#include <algorithm>
#define SORT(a, n) sort(begin(a), begin(a) + n) //nlogn sort

//Title:Mighty Friend [MTYFRI]
using namespace std;

int even_pos_score(vector<int> a){
    int score = 0;
    for(int i=0; i<a.size(); i+=2){
        score += a[i];
    }
    return score;
}

int odd_pos_score(vector<int> a) {
    int score = 0;
    for (int i = 1; i < a.size(); i += 2) {
        score += a[i];
    }
    return score;
}

int main() {
    int T; //test cases
    cin >> T;
    vector<int> results;

    for (int i = 1; i < T + 1; i++) {
        int N, K;
        cin >> N >> K;

        //get the list of elements
        vector<int> elements;
        elements.clear();
        for (int j = 0; j < N; j++) {
            int ele;
            cin >> ele;
            elements.push_back(ele);
        }

        //----write from here-----
        int motu_score = even_pos_score(elements);
        int tomu_score = odd_pos_score(elements);

        if(tomu_score > motu_score){
            results.push_back(1);
        } else {
            vector<int> sorted_elements = elements;
            SORT(sorted_elements, N);
            int j = 0; //left to right movement
            int k = N-1; //right to left movement
            while((j<k) && (K>0)) { 
                //take max
                int max = sorted_elements[k];
                //find position of max in original array
                vector<int>::iterator it;
                it = find(elements.begin(), elements.end(), max);
                int max_pos = distance(elements.begin(), it);
                //if even position, go ahead
                if(max_pos%2 == 0){
                    int min_pos;
                    //find min_pos which is odd
                    do{
                        //find min
                        int min = sorted_elements[j];
                        //find position of min in original array
                        it = find(elements.begin(), elements.end(), min);
                        min_pos = distance(elements.begin(), it);
                        //if not odd position, choose next minimum element
                        if (min_pos % 2 == 0){
                            j++;    
                        }
                    }while((min_pos %2 == 0) && (j<k));

                    if ((min_pos %2 == 1) && (j < k)){
                        swap(elements[min_pos], elements[max_pos]);
                        K--;
                    } 
                }
                k--;
                
            }

            motu_score = even_pos_score(elements);
            tomu_score = odd_pos_score(elements);

            if (tomu_score > motu_score) {
                results.push_back(1);
            } else {
                results.push_back(-1);
            }
        }


    } //for each test case

    //print results
    //1   -> YES
    //-1  -> NO
    for (int i = 0; i < results.size(); i++){
        if(results[i] > 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

//