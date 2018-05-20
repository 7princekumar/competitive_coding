#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long
 
vector<ll>v1,v2;
void solve(ll a[],ll s,ll e,ll x)
{
    if(s==e||s>e)
        return;
    ll mid=(s+e)/2;
    if(mid==x)
        return;
    else if(mid<x)
    {
        v1.push_back(a[mid]);// x index se chhota.
        solve(a,mid+1,e,x);
    }
    else
    {
        v2.push_back(a[mid]); // x index se bada.
        solve(a,s,mid-1,x);
    }
}
 
int main()
{
    ll i,j,k,x,y,T,t,n,m;
    scanf("%lld",&T);   
    while(T--)
    {
        scanf("%lld %lld",&n,&t);   
        ll a[n];
        unordered_map<ll,ll>mp1;
        vector<ll>mp;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);   
            mp.push_back(a[i]);
            mp1[a[i]]=i;
        }
        sort(mp.begin(),mp.end());
        while(t--)
        {
            scanf("%lld",&k);   
            x=mp1[k];
            v1.clear();
            v2.clear();
            solve(a,0,n-1,x);
            /*sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            */
            ll left_small=0,left_greater=0,right_small=0,right_greater=0;
            for(auto i:v1)
            {
                if(i>k)
                    left_greater++;
                else
                    left_small++;
            }
            for(auto i:v2)
            {
                if(i<k)
                    right_small++;
                else
                    right_greater++;
            }
 
            ll ans=0;
            ans+=min(left_greater,right_small);
            if(left_greater==right_small)
            {
                printf("%lld\n",ans);
                continue;
            }
            left_greater-=ans;
            right_small-=ans;
            ll p,q;
            p=ans;
            ll chhota,bada;
            if(left_greater)
            {
                auto chhota = lower_bound(mp.begin(), mp.end(),k) - mp.begin();
                chhota-=(p+left_small);
                if(chhota<left_greater)
                {
                    printf("-1\n");
                    continue;
                }
                else
                    ans+=left_greater;
            }
            else if(right_small)
            {
                auto bada=(n-1)-(lower_bound(mp.begin(), mp.end(), k) - mp.begin());
                bada-=(p+right_greater);
                //cout<<"b"<<bada<<"\n";
                if(bada<right_small)
                {
                    printf("-1\n");
                    continue;
                }
                else
                    ans+=right_small;
            }
           /* for(auto i:v1)
                cout<<i<<" ";
            cout<<"\n";
            for(auto i:v2)
                cout<<i<<" ";
            cout<<"\nx\n";*/
            printf("%lld\n",ans);
        }
    }
    return 0;
} 