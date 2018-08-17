#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

//------------------GCD-----------------
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


// Function to find gcd of array of
// numbers
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}
//------------------GCD-end----------------




//--------------------PERMUTATION-------------------
//print permutations
void print_permutations(int n){
    n = 3;
    //fill the vect (must be sorted to get all permuations)
    vector <int> vect;
    for (int i = 1; i <= n; i++)
        vect.push_back(i);

    //print the vect
    for (int i=0; i<vect.size(); i++)
        cout << vect[i] << " ";
    cout <<endl;

    //print till permutation possible.
    while(next_permutation(vect.begin(), vect.end()) ){
        for (int i=0; i<n; i++)
            cout << vect[i] << " ";
        cout<<endl;
    }
}

//--------------------PERMUTATION-end-----------------





//---------------------prime-factors------------------
vector<int> primeFactors(int n) {
    vector<int> factors;
    // Print the number of 2s that divide n
    while (n%2 == 0){
        factors.push_back(2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2) {
        // While i divides n, print i and divide n
        while (n%i == 0) {
            factors.push_back(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        factors.push_back(n);

    return factors;
}

//--------------------primt-factors-end----------------