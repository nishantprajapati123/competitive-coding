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
    vector<int>A(n);
    int largest=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(largest<A[i]) largest=A[i];
    }
    vector<ll>cnt(largest+1,0),dp(largest+1);
    for(int x:A)
        cnt[x]++;
    //sequence of only 0's
    dp[0]=0;
    //sequence of 0's and 1's
    dp[1]=cnt[1]*1;
    for(int i=2;i<largest+1;i++)
        dp[i]=max(dp[i-1],dp[i-2]+(i*cnt[i])); //select or not select, if select then pick i-2th and add with no*freq(no) or if not select copy previous value
     cout<<dp[largest]<<"\n";
}
