#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
ll n,c;
ll stall[100001];
    int fnc(ll x)
    {
    	ll temp;
    	temp=1;
    	ll prev;
    	prev=stall[0];
    	for(ll i=1;i<n;i++)
    	{
    		if(stall[i]-prev>=x)
    		{
    			temp++;
    			if(temp==c)
    				return 1;
    			prev=stall[i];
    		}
    	}
    	return 0;
    }


    void binsearch()
    {
    	ll l,r,mid;
    	l=0;
    	r=stall[n-1];
    	while(l<r)
    	{
    		mid=(l+r)/2;
    		if(fnc(mid)==1)
    			l=mid+1;
    		else
    			r=mid;
    	}
    	cout<<(l-1)<<"\n";
    }

    int main()
    {
        fastIO
    	ll t,i;
    	cin>>t;;
    	while(t--)
    	{
    		cin>>n>>c;
    		for(ll i=0;i<n;i++)
    			cin>>stall[i];
    		sort(stall,stall+n);
    		binsearch();
    	}
    	return 0;
    }
