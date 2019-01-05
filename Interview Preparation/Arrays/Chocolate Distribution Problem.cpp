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
    cin >> t;

    while(t--)
    {
        ll n,m;
        cin>>n;
        vector<ll>A(n);
        for(ll i=0;i<n;i++)
            cin>>A[i];
        cin>>m;
        sort(A.begin(),A.end());
        ll beg=0,en=m-1;
        ll value=INT_MAX;
        while(en<n)
        {
            if(A[en]-A[beg] < value) value = A[en]-A[beg];
            beg++,en++;
        }
        cout<<value<<"\n";
    }
}
