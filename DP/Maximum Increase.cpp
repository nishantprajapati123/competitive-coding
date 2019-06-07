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
    cin>>n;
    vector<ll>A(n);
    for(int i=0;i<n;i++)    cin>>A[i];
    vector<ll>dp(n,1);
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[i-1])
            dp[i] = dp[i-1]+1;
    }
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}

