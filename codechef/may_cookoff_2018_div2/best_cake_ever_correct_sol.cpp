#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <iterator>
using namespace std;
 
//#include <bits/stdc++.h>
#define f(a, n) for (int a=0; a<n; a++)
#define F(a, n) for (int a=1; a<=n; a++)
#define pii pair<long long, long long>
using namespace std;
 
int T, n, k;
 
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	f(t, T){
		cin>>n>>k;
		if (n == 1) cout<<k<<endl;
		else if (k == 1){
			f(i, n) cout<<1<<" ";
			cout<<endl;
		}
		else if (k == 2){
			cout<<"2 ";
			f(i, n-1) cout<<1<<" ";
			cout<<endl;
		}
		else if (k == 3){
			if (n%2){
				f(i, n) cout<<3<<" ";
				cout<<endl;
			}
			else{
				cout<<"2 ";
				f(i, n-1) cout<<"1 ";
				cout<<endl;
			}
		}
		else{
			int tmp = k, cnt = -1;
			while (tmp) {
				tmp >>= 1;
				cnt ++;
			}
            
			int first = 1 << cnt;
			int second = first - 1;
			second -= (n%2 == 1?1:0);
			cout<<first<<" ";
			cout<<second<<" ";
			f(i, n-2) cout<<"1 ";
			cout<<endl;
		}
	}
}