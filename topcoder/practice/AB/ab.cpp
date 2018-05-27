#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

#define SORT(a, n) sort(begin(a), begin(a) + n) 
#define MOD 1000000007
//int max= *max_element(v.begin(), v.end());

using namespace std;

void print_i_v(vector<int> &v){
    for(int j=0; j<v.size(); j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}



vector<int> primeFactors(int n) {
    vector<int> factors;

    while (n%2 == 0){
        factors.push_back(2);
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i+2) {
        while (n%i == 0) {
            factors.push_back(i);
            n = n/i;
        }
    }

    if (n > 2)
        factors.push_back(n);

    return factors;
}


class AB {
    public:
    string createString(int N, int K){
        vector<char>result;

        string str = "";
        //special case handler
        if(K == 0){
            for(int i=0; i<N-1; i++){
                result.push_back('B');
            }
            result.push_back('A');
            string answer(result.begin(),result.end());
            return answer;
        }
        vector<int> factors = primeFactors(K);
        //print_i_v(factors);

        
        //for checking if no string satisfies the conditions given
        int max_pair_for_odd = (N/2) * ((N+1)/2);
        int max_pair_for_even = (N/2) * (N/2);

        //cout<<"odd expr: " <<max_pair_for_odd <<endl;
        //cout<<"even expr: "<<max_pair_for_even<<endl;
        if(N%2 == 0){
            if(max_pair_for_even < K){
                return str; //empty string
                exit(0);
            } 
        } else {
            if(max_pair_for_odd < K){
                return str; //empty string
                exit(0);
            } 
        }

        //get proper x,y such that x*y = K and x+y <= N,
        int x =1; //x denotes no of A
        int y =1; //y denotes no of B
        for(int i=0; i<factors.size(); i++){
            x = factors[i]; y =1;
            for(int j=0; j<factors.size(); j++){
                if(i != j) {
                    y *= factors[j];
                }  
            }

            if(x+y <= N){
                break;
            }
        }

        //cout<<"x: "<<x<<endl;
        //cout<<"y: "<<y<<endl;


        for(int i=0; i< N-(x+y); i++){
            result.push_back('B'); //padding
        }
        for(int i=0; i< x; i++){ //put as many A as 'x'
            result.push_back('A');
        }
        for(int i=0; i< y; i++){
            result.push_back('B'); ////put as many B as 'y'
        }

        string answer(result.begin(),result.end());
        return answer;
    }
};


int main() {
    int N, K;
    cin>>N >>K;
    
    AB obj;
    cout<<obj.createString(N,K);
    return 0;
}

//
