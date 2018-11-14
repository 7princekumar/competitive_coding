#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ppi pair<int,int>
int X[4]={0,0,-1,+1};
int Y[4]={-1,+1,0,0};
int n,m;
bool t(int x,int y)
{
	if(x<0 || x>=n || y<0 || y>=m) return false;
	return true;
}
int main()
{
	cin>>n>>m;
	int A[n][m],mrk[n][m],ans[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>A[i][j];
	int an=-1,pos=0;
	for(int i=1;i<=100;i++)
	{
		memset(mrk,0,sizeof(mrk));
		memset(ans,-1,sizeof(ans));
		priority_queue<pii,vector<pii>,greater<pii> >pq;
		pq.push(pii(fabs(i-A[0][0]),0));
		ans[0][0]=fabs(i-A[0][0]);
		pii par[n][m];
		while(!pq.empty())
		{
			pii pp=pq.top();pq.pop();
			int a=pp.first,b=pp.second;
			int x=b/m,y=b%m;
			if(mrk[x][y]!=0) continue;
			mrk[x][y]=1;
			for(int j=0;j<4;j++)
			{
				int k=j;
				{
					int xx=x+X[j],yy=y+Y[k];
					if(t(xx,yy) && (ans[xx][yy]==-1 || ans[xx][yy]>a+fabs(A[xx][yy]-i)))
					{
						ans[xx][yy]=a+fabs(A[xx][yy]-i);
						pq.push(pii(ans[xx][yy],xx*m+yy));
						par[xx][yy]=pii(x,y);
					}
				}
			}
		}
		if(an==-1) an=ans[n-1][m-1],pos=i;
		else if(ans[n-1][m-1]<an) an=ans[n-1][m-1],pos=i;
	}
	cout<<an<<"\n";
	return 0;
}
/*
6 3
49 66 30
9 91 6
32 100 52
23 83 42
71 73 37
90 47 22
*/