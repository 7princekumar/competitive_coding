#include <bits/stdc++.h>
using namespace std;
#define TRACE
#ifdef TRACE
#define TR(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define TR(...)
#endif
typedef long long                LL;
typedef vector < int >           VI;
typedef pair < int,int >         II;
typedef vector < II >            VII;
#define MOD                      1000000007
#define EPS                      1e-12
#define N                        200100
#define PB                       push_back
#define MP                       make_pair
#define F                        first 
#define S                        second
#define ALL(v)                   v.begin(),v.end()
#define SZ(a)                    (int)a.size()
#define FILL(a,b)                memset(a,b,sizeof(a))
#define SI(n)                    scanf("%d",&n)
#define SLL(n)                   scanf("%lld",&n)
#define PLLN(n)                  printf("%lld\n",n)
#define PIN(n)                   printf("%d\n",n)
#define REP(i,j,n)               for(LL i=j;i<n;i++)
#define PER(i,j,n)               for(LL i=n-1;i>=j;i--)
#define endl                     '\n'
#define fast_io                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define FILEIO(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
 
inline int mult(int a , int b) { LL x = a; x *= LL(b); if(x >= MOD) x %= MOD; return x; }
inline int add(int a , int b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline int sub(int a , int b) { return a - b < 0 ? MOD - b + a : a - b; }
LL powmod(LL a,LL b) { if(b==0)return 1; LL x=powmod(a,b/2); LL y=(x*x)%MOD; if(b%2) return (a*y)%MOD; return y%MOD; }
int f(LL x) {
  if(x < 10) return x;
  string s = to_string(x);
  LL y = 0;
  for(char i : s)
    y += int(i-'0');
  return f(y);
}
LL a[N];
LL pref[N];
int main() {
  int n,q; SI(n); SI(q);
  assert(n <= int(1e5));
  assert(q <= int(1e5));
  set <LL> S;
  REP(i,1,n+1) {
    SLL(a[i]);
    assert(a[i] <= LL(1e18));
    assert(!S.count(a[i]));
    S.insert(a[i]);
  }
  REP(i,1,n+1) a[i] = f(a[i]);
  sort(a+1,a+n+1);
  REP(i,1,n+1) pref[i] = pref[i-1] + a[i];
  while(q--) {
    int t,k; SI(t); SI(k);
    assert(t >= 1 && t <= 2);
    assert(k >= 1 && k <= n);
    if(t == 1) 
      PLLN(pref[n] - pref[n-k]);
    else
      PLLN(pref[k]);
  }
  return 0;
}