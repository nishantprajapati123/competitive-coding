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
int solve(vector<int>&P, int n)
{
    sort(P.begin(), P.end(), greater<ll>());
    ll maxP = 0;
    for(int i=0;i<n;i++)
        maxP += max(0,P[i] - i);

    return maxP % MOD;
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
        vector<int>P(n);
        for(int i=0;i<n;i++)    cin>>P[i];

        cout<<solve(P,n)<<"\n";
    }
    return 0;
}

