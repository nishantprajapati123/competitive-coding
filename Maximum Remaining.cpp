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
    ll n;
    cin>>n;
    vector<ll>A(n);
    for(ll i=0;i<n;i++) cin>>A[i];
    sort(A.begin(),A.end());
    ll mx = A[n-1];
    ll res,i=n-2;
    while(i>=0)
    {
        if(A[i]!=mx)
        {
            cout<<A[i];
            break;
        }
        mx = A[i];
        i--;
    }
    if(i==-1)   cout<<0;
    return 0;
}
