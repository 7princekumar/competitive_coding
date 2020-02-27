// ans = x^2 + 2.x.y
#define M (1000000007)
int balancedBTs(int h) {
    if(h == 0 || h == 1) return 1;
    long long x = balancedBTs(h-1) % M;
    long long y = balancedBTs(h-2) % M;
    return ((x*x)%M + (2*(x*y)%M)%M) %M;
}
