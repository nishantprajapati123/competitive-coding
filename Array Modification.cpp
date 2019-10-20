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
        int n;
        ll k;
        cin>>n>>k;
        vector<ll>A(n);
        for(int i=0;i<n;i++)    cin>>A[i];

        ll iter = (k-1)%(3*n);
        ll mid = A[n/2];
        for(ll i=0;i<=iter;i++)
        {
            A[i%n] = (A[i%n] ^ A[n-(i%n)-1]);
        }
        if((n&1) && (k-1 >= (n/2)))
        {
            A[n/2] = 0;
        }
        for(ll x:A)
            cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}

