#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstdbool>
#include <string>

using namespace std;


void print_i_v(vector<int> &v){
    for(unsigned int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}


bool is_unique(string time){
    int present[10];
    for(int i=0; i<10; i++){
        present[i] = 0;
    }
    for(int i=0; i< time.length(); i++){
        if(time[i] != ':'){
            if(present[time[i] - '0'] == 1){
                return false;
            }else{
                present[time[i] - '0'] = true;
            }
        }
    }
    return true;
}

void increment(string& time){
    int h,m,s;
    h = stoi(time.substr(0,2));
    m = stoi(time.substr(3,2));
    s = stoi(time.substr(6,2));
    // cout <<"time: "<< h << " " << m << " " << s << " " << endl;
    if(s == 59){
        s = 0;
        m++;
        if(m == 60){
            m = 0;
            h++;
            if( h == 24){
                h = 0;
            }
        }
    }else{
        s++;
    }

    
    string new_time;
    if(h >= 10){
        new_time += (to_string(h));
    }else{
        new_time += ("0");
        new_time += (to_string(h));
    }
    new_time.push_back(':');


    if(m >= 10){
        new_time += (to_string(m));
    }else{
        new_time += ("0");
        new_time += (to_string(m));
    }
    new_time.push_back(':');


    if(s >= 10){
        new_time += (to_string(s));
    }else{
        new_time += ("0");
        new_time += (to_string(s));
    }

    time = new_time; 
    // return new_time;
}



int main() {
    int T; //test cases
    cin >> T;
    vector<string> results;

    for(int tt=0; tt < T; tt++){
        string time;
        cin >> time;

        //----write from here-----
        while(!is_unique(time)){
            increment(time);
            cout << time;
            if(is_unique(time)){
                cout << "  Unique" << endl;
            }else{
                cout << "  Not" << endl; 
            }
        }
        results.push_back(time);
        
    
    } //for each test case

    for (unsigned int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }

    return 0;
}

//
