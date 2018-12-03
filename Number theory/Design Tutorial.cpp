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
int prime(ll x)
{
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    fastIO
    ll n;
    cin>>n;
    ll l,h;
    if(n%2==0)
        l=h=(n/2);
    else
        l=n/2,h=l+1;
    while(1)
    {
        if(prime(l) || prime(h))
            l--,h++;
        else
        {
            cout<<l<<" "<<h;
            break;
        }
    }
}
