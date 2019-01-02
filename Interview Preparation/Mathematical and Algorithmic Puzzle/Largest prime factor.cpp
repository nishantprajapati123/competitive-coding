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
    int t;
    cin>>t;
    while(t--)
    {
        vector<ll>res;
        ll n;
        cin>>n;
        for(ll i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                res.pb(i);
                n/=i;
            }
        }
        if(n!=1)
            res.pb(n);
        cout<<res.back()<<"\n";
    }

}
