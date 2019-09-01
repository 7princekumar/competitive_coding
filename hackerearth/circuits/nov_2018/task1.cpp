#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cstdbool>
#define int long long

using namespace std;

void print_vc(vector<char>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

pair<int,int> calculate_ratio(int a, int b){
    pair<int,int> p;
    p.first = a;
    p.second = b;
    return p;
}

#undef int
int main(){
#define int long long
    int T; cin >> T;
    while(T--){
        int N; cin>> N;

        //take input
        vector<char> v; int count; char letter;
        for(int i=0; i<N; i++){
            cin >> count >> letter;
            if(letter == 'A'){
                while(count--) v.push_back('A');
            }else{
                while(count--) v.push_back('B');
            }
        }

        //work
        int countA = 0;
        int countB = 0;
        int score = 0;
        int i = 0, j; //using i for traversal
        bool is_ratio_formed = false;
        while(i < v.size()){
            if(is_ratio_formed == false)
            {
                if(v[i] == 'A'){ //sequence starts with A FIRST
                    //count consequitive A
                    while(i < v.size() && v[i] == 'A') i++, countA++; 
                    //count consequitive B
                    j = 0;
                    while((i < v.size()) && (v[i] != 'A') && (j < countA)) i++, countB++;
                }else{ //sequence starts with B FIRST
                    //count consequitive B
                    while(i < v.size() && v[i] == 'B') i++, countB++; 
                    //count consequitive A
                    j = 0;
                    while((i < v.size()) && (v[i] != 'B') && (j < countB)) i++, countA++;
                }

                pair<int, int> ratio = calculate_ratio(countA, countB);
                score++;
                is_ratio_formed = true;
            }
            else
            {
                if(v[i] == 'A'){
                    while(i < v.size() && v[i] == 'A') i++, countA++;  
                }else{

                }  
            }
        }

    }
    return 0;
}