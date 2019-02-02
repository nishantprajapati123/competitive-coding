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
    ll n,m,i,j;
    cin>>n>>m;
    vector<ll>A(n),B(m);
    for(ll k=0;k<n;k++)
        cin>>A[k];
    for(ll k=0;k<m;k++)
        cin>>B[k];
    ll mn=INT_MAX,mx=INT_MIN,pos1=0,pos2=0;
    for(ll k=0;k<n;k++)
    {
        if(mn>A[k])
            mn=A[k],pos1=k;
    }
    for(j=0;j<m;j++)
        cout<<pos1<<" "<<j<<"\n";
    for(ll k=0;k<m;k++)
    {
        if(mx<B[k])
            mx=B[k],pos2=k;
    }
    for(i=0;i<n;i++)
    {
        if(i==pos1) continue;
        cout<<i<<" "<<pos2<<"\n";
    }
    return 0;
}
