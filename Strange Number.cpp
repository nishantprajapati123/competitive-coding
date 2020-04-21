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
ll factorize(ll n)
{
    ll cnt = 0;
    for(ll i=2;i*i<=n;i++)
    {
        while(n%i == 0)
        {
            cnt++;
            n /= i;
        }
    }
    if(n!=1)
        cnt++;
    return cnt;
}
int solve(ll x, ll k)
{
   if(factorize(x) >= k)
        return 1;
   else
        return 0;
}
int main()
{
    fastIO
    int t;
    cin>>t;
    while(t--)
    {
        ll x, k;
        cin>>x>>k;
        cout<<solve(x,k)<<"\n";
    }
    return 0;
}

