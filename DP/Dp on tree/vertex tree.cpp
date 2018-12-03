#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%I64d",&x)
#define ss(s)	scanf("%s",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int N = 1e5;
int dp[N][2];
vi g[N];
void dfs(int u, int par)
{
    for(int child:g[u])
    {
        if(child==par)  continue;
        dfs(child,u);
        dp[u][0]=0;
        dp[u][1]=0;
    }
    int s1=0,s2=0;
    for(int child:g[u])
    {
        //not including root vertex
        s1+=dp[child][1];
        //including root vertex
        s2+=min(dp[child][0],dp[child][1]);
    }
    dp[u][0]=s1;
    dp[u][1]=1+s2;

}
int main(){
    int n,i;
    cin>>n;
    fo(i,n-1)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    cout<<min(dp[1][0],dp[1][1]);
}
