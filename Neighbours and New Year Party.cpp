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
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>A(n);
        vector<ll>M(n,0);
        for(ll i=0;i<n;i++) cin>>A[i];
        M[0] = A[0];
        M[1] = max(M[0],A[1]);
        for(ll i=2;i<n;i++)
            M[i] = max(M[i-1],max(M[i-2]+A[i],A[i]));
        for(auto i:M)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}

