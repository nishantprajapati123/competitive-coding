#include <bits/stdc++.h>
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
int main()
{
    fastIO
    ll n,m;
    cin>>n>>m;
    vector<ll>A(n+1);
    A[0]=0;//just for avoiding 0-based indexing
    unordered_map<ll,int>mp;
    for(int i=1;i<n+1;i++) cin>>A[i];
    vector<ll>res(n+1,0);
    //single element is always unique
    res[n] = 1;
    mp[A[n]]++;
    for(int i=n-1;i>0;i--)
    {
        if(mp.find(A[i])== mp.end())
            res[i] = 1+res[i+1],mp[A[i]]++;
        else
            res[i] = res[i+1];
    }
    while(m--)
    {
        ll l;
        cin>>l;
        cout<<res[l]<<"\n";
    }
    return 0;
}
