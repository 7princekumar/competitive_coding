#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdbool>
#include<vector>
using namespace std;

void troubleSort(vector<int> &elements){
    bool done = false;
    while(!done){
        done = true;
        for(int i=0; i<elements.size() -2; i++){
            if(elements[i] > elements[i+2]){
                done = false;
                //reverse the sublist from L[i] to L[i+2], inclusive
                int temp;
                temp          = elements[i];
                elements[i]   = elements[i+2];
                elements[i+2] = temp;
            }
        }
    }
}

int isOK(vector<int> &elements){
    for(int i=0; i<elements.size() -1; i++){
        if(elements[i] > elements[i+1]){
            return i;
        }
    }
    cout<<endl;
    return -1; //correct
}


int main(){
    //get test cases
    int test_cases;
    cin>>test_cases;
    
    //score array
    vector<int> scores;
    
    for(int i=1; i<test_cases+1; i++){
        //get the N(no of elements to sort
        int N;
        cin>>N;
        
        //get the list of elements to sort
        vector<int> elements;
        elements.clear();
        for(int i=0; i<N; i++){
            int ele;
            cin>>ele;
            elements.push_back(ele);
        }
        
        //sort
        troubleSort(elements);

        //check
        int ch = isOK(elements);
        scores.push_back(ch);
    } //for each test case
    
    for(int i=0; i<scores.size(); i++){
        if(scores[i] == -1){
            cout<<"Case #"<<i+1<<": OK"<<endl;
        }else{
            cout<<"Case #"<<i+1<<": "<<scores[i]<<endl;
        }
    }
    
    return 0;
}


