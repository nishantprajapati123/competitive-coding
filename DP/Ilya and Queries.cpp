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
    string s;
    getline(cin,s);
    ll m;
    cin>>m;
    ll n = s.length();
    vector<int>dp(n,0),prefix(n,0);
    for(int i=0;i<n-1;i++)
    {
        if(s[i] == s[i+1])
            dp[i] = 1;
    }
    prefix[0]=dp[0];
    for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]+dp[i];
    while(m--)
    {
        ll l,r,sum=0;
        cin>>l>>r;
        if(l-1!=0)
            cout<<prefix[r-2]-prefix[l-2]<<"\n";
        else
            cout<<prefix[r-2]<<"\n";
    }
//    for(int i:prefix)
//        cout<<i<<" ";
    return 0;
}
