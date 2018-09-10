//largest prime number
#include <iostream>
#include <vector>
#include <cstdbool>
#include <cmath>
#include <unordered_set>
using namespace std;

long solve(long num){
    int largest_prime_factor = 1;
    while(num % 2 == 0){
        num = num >> 1;
        largest_prime_factor = max(largest_prime_factor, 2);
    }

    //now num has no even factors remaining -> increment loop with i+=2
    long sqrt_num = sqrt(num);
    for(int i=3; i< sqrt_num; i+=2){
        while(num % i == 0){
            num = num / i;
            largest_prime_factor = max(largest_prime_factor, i);
        }
    }

    return largest_prime_factor;
}

int main(){ 
    long num = 600851475143;
    cout<< solve(num) << endl;
    return 0;
}