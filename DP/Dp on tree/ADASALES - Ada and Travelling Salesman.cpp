#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M=300000;
vector<ll> g[300000];
ll  in[300000], out[300000];
void dfs1(ll u, ll par,ll A[]){
	in[u] = 0;
	for(ll v:g[u]){
		if (v == par) continue;
		dfs1(v, u,A);
		ll tu=0;
		if ((A[v]-A[u])>0)
		tu=(A[v]-A[u]);
		in[u] = max(in[u], tu+in[v]);
	}
}
void dfs2(ll u, ll par,ll A[]){
	ll mx1(-1), mx2(-1);
    //find top 2 maximum values of in[v]
    for(ll v: g[u]){
            if(v == par) continue;
            ll tu=0;
    		if ((A[v]-A[u])>0)
    		tu=(A[v]-A[u]);
            if(in[v]+tu >= mx1) mx2 = mx1, mx1 = in[v]+tu;
            else if(in[v]+tu > mx2) mx2 = in[v]+tu;
    }
	for(ll v:g[u]){
		if (v == par) continue;
		ll use = mx1;
		ll tu=0;
		if ((A[u]-A[v])>0)
		tu=(A[u]-A[v]);
		ll tu2=0;
    	if ((A[v]-A[u])>0)
    		tu2=(A[v]-A[u]);
		if(mx1 == in[v]+tu2)
			use = mx2;
		out[v] = max(tu+out[u], tu+use);
		//cout<<v<<" "<<use<<endl;
		dfs2(v, u,A);
	}
}
int main()
{
	ll N,Q;
	cin>>N>>Q;
	ll A[N];
	for(ll i=0;i<N;i++)
	cin>>A[i];
	ll n=N-1;
	ll a,b;
	while(n--)
	{
		cin>>a>>b;
		//a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(0,-1,A);
	out[0]=0;
	dfs2(0,-1,A);
	while(Q--){
	 cin>>a;
	 //a--;
	cout<<max(in[a],out[a])<<endl;
	}
}
