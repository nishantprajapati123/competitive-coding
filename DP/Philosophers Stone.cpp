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
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int stone[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cin>>stone[i][j];
        }
        int dp[r][c];
        for(int i=0;i<c;i++)
            dp[0][i] = stone[0][i];
        for(int i=1;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(j == 0)
                    dp[i][j] = stone[i][j] + max(dp[i-1][j],dp[i-1][j+1]);
                else if(j==c-1)
                    dp[i][j] = stone[i][j] + max(dp[i-1][j],dp[i-1][j-1]);
                else
                    dp[i][j] = stone[i][j] + max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
            }
        }
//        for(int i=0;i<r;i++)
//        {
//            for(int j=0;j<c;j++)
//                cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }
        int ans = INT_MIN;
        for(int i = 0;i<c;i++)
        {
            if(dp[r-1][i]>ans)  ans = dp[r-1][i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
