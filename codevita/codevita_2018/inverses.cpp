#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

long long phi(long long x)
 {
   long long ret = 1,i,pow;
   for (i = 2; x != 1; i++) 
   {
     pow = 1;
     if(i>sqrt(x))break;
     while (!(x%i)) 
     {
       x /= i;
       pow *= i;
     }
     ret *= (pow - (pow/i));
    }
    if(x!=1)ret*=(x-1);
    return ret;
}

int main() {
    ll N;
    cin >> N;
    cout<< phi(N);
    return 0;
}

//