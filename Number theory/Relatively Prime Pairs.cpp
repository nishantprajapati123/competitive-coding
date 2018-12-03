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
    ll l,r;
    cin>>l>>r;
    ll n=(r-l+1)/2;
    cout<<"YES\n";
    for(int i=0;n;i+=2,n--)
        cout<<l+i<<" "<<l+i+1<<"\n";
}
