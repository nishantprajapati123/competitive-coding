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
void printEqualModNumbers (vector<ll>arr, ll n)
{

    sort(all(arr));
    ll d = arr[n-1] - arr[0];

    vector <ll> v;
    vector<ll>ans;
    for (ll i=2; i*i<=d; i++)
    {
        if (d%i == 0)
        {
            v.push_back(i);
            if (i != d/i)
                v.push_back(d/i);
        }
    }
    for (ll i=0; i<v.size(); i++)
    {
        ll temp = arr[0]%v[i];
        ll j;
        for (j=1; j<n; j++)
            if (arr[j] % v[i] != temp)
                break;
        if (j == n)
            ans.pb(v[i]);
    }
    sort(all(ans));
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
int main()
{
    fastIO
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    printEqualModNumbers(arr,n);
}
