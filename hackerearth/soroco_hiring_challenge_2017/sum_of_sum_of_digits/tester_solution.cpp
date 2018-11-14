#include<bits/stdc++.h>
#define inf 1e18
#define ll long long
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	assert(n>=1 && n<=100000);
	assert(q>=1 && q<=100000);
	int dv[100005];
	map<ll,int>mp;
	for(int i=0;i<n;i++)
	{
		ll temp;
		cin>>temp;
		assert(!mp[temp]);
		mp[temp]++;
		assert(temp>=1 && temp<=inf);
		int ans;
		if(temp<10)ans=temp;
		while(temp>=10)
		{
			ll val=temp;ans=0;
			while(val)
			{
				ans+=val%10;
				val/=10;
			}
			temp=ans;
		}
		dv[i]=ans;
		//cout<<dv[i]<<"\n";
	}
	int pre[100005];
	sort(dv,dv+n);
	pre[0]=dv[0];
	for(int i=1;i<n;i++)
		pre[i]=pre[i-1]+dv[i];
	while(q--)
	{
		int type;
		int k;
		cin>>type>>k;
		assert(type==1 || type==2);
		assert(k>=1 && k<=n);
		if(type==1)
			(k==n)?cout<<pre[n-1]<<"\n":cout<<pre[n-1]-pre[n-(k+1)]<<"\n";
		else
			cout<<pre[k-1]<<"\n";
	}
	return 0;
}