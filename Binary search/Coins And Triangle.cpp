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
ll calCoin(ll m)
{
    return (m*(m+1))/2;
}
void maxHeight(ll n)
{
    ll l=1,h=n;
    while(l<h)
    {
        ll mid = (l+h)/2;
        if(calCoin(mid)==n)
        {
            cout<<mid<<"\n";
            return;
        }
        else if(calCoin(mid)<n)
            l = mid+1;
        else
            h = mid;

    }
    cout<<l-1<<"\n";
}
int main()
{
    fastIO
    int t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin>>n;
        if(n==1)
            cout<<1<<"\n";
        else
            maxHeight(n);
    }
    return 0;
}
