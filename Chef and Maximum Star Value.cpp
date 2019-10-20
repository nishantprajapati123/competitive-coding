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
void getFactor(ll x, unordered_map<ll, ll>&mp)
{
    for(ll i = 1; i*i<=x; i++)
    {
        if(x%i == 0)
        {
            if(i == (x/i))
                mp[i]++;
            else
            {
                mp[i]++;
                mp[(x/i)]++;
            }
        }
    }
}
int main()
{
    fastIO
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>A(n);
        for(int i=0;i<n;i++)    cin>>A[i];

        unordered_map<ll, ll>mp;
        ll ans = INT_MIN;
        for(ll x:A)
        {
            ans = max(ans, mp[x]);
            getFactor(x, mp);
        }
        cout<<ans<<"\n";

    }
    return 0;
}

