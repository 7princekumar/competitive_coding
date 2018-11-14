/*logic ------------
*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<bitset>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<stdio.h>
#include<queue>
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007 // 10**9 + 7
#define INF 1e9
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a),0,sizeof(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, b, a) for (int i = b; i > a; i--)
#define all(v) v.begin(), v.end()
#define GETCHAR getchar_unlocked
#define pi(n) printf("%d\n",n)
#define pll(n) printf("%lld\n",n)
#define rk() int t; scanf("%d",&t); while(t--)
using namespace std;
const double pi = acos(-1.0);
//freopen("in","r",stdin);
//freopen("out","w",stdout);
const int er[8] = {-1,-1,0,1,1,1,0,-1};
const int ec[8] = {0,1,1,1,0,-1,-1,-1};
typedef unsigned long long ull;
typedef long long ll;
typedef long l;
typedef pair<int,int> pii;
typedef vector<int> vec;
typedef vector<pii> vpii;
ll po(ll a,ll p)
{ll ret = 1;while(p){if(p&1)ret = (ret*a)%mod;a=(a*a)%mod;p=p>>1;}return ret%mod;}
int n, m, ans;
int a[105][105];
int c[105][105];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int inside(int x, int y){
  return x>=0 && x<n && y>=0 && y<m;
}
bool isless(int x, int v){
  return x==-1 || x>v;
}
class Point{
  public:
    int x, y, d;
    Point(int _x=0, int _y=0, int _d=0) {x=_x; y=_y; d=_d;}
    bool operator<(const Point &p) const{
      if(d!=p.d) return d>p.d;
      if(x!=p.x) return x<p.x;
      return y < p.y;
    }
};
int go(int w){
  priority_queue<Point> q;
  memset(c,-1,sizeof(c));
  c[0][0] = abs(w-a[0][0]);
  q.push(Point(0, 0,c[0][0]));
  while(!q.empty()){
    Point p = q.top(); 
	q.pop();
    int x=p.x,y=p.y,d=p.d;
    if(d==c[x][y]){
      for(int f= 0;f<4;f++){
        int nx=x+dx[f],ny=y+dy[f],v=0;
        if(inside(nx, ny) && isless(c[nx][ny], v=d+abs(w-a[nx][ny]))){
          q.push(Point(nx,ny,v));
          c[nx][ny]=v;
        }
      }
    }
  }
  return c[n-1][m-1];
}
int u[105]={0};
int main(){
  //freopen("input20.txt","r",stdin);
//freopen("input20out.txt","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&a[i][j]);
    }
  }
  ans=-1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){ 
		if(!u[a[i][j]]){
      		u[a[i][j]]=1;
      		int r=go(a[i][j]);
      		//cout<<a[i][j]<<" "<<r<<endl;
      		if(ans<0 || ans>r) ans=r;
    	}
    }
  }
  printf("%d\n",ans);
  return 0;
}