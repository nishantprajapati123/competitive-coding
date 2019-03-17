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
    int n;
    ll l;
    cin>>n>>l;
    vector<ll>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a.begin(),a.end());
    double res = -INF;
    if(res < a[0]-0.0)
        res = a[0];
    for(int i=0;i<n-1;i++)
    {
        if(res< (a[i+1]-a[i])/2.0)
            res = (a[i+1]-a[i])/2.0;
    }
    if(res < l-a[n-1])
        res = l-a[n-1];
    cout<<fixed<<setprecision(10)<<res;
    return 0;
}
