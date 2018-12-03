#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
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
vi g[N];
int val[N];
int dp[N][2];
void dfs(int u, int par)
{
    for(int child:g[u])
    {
        if(child==par)  continue;

        dfs(child,u);
        dp[u][0]=val[u];
        dp[u][1]=0;
    }
    int taking_u=val[u],not_taking_u=0;
    for(int x:g[u])
    {
        if(x==par) continue;
        taking_u+=dp[x][1]; //calculate sum of child when parent u is taken
        not_taking_u+=dp[x][0]; //calculate sum of child when parent u is not taken
    }
    //(i) parent of u is taken then sure we can't take u
    dp[u][1]=not_taking_u;
    //(ii) parent of u is not taken then u've two option either take u or not
    dp[u][0]=max(taking_u,not_taking_u);
}
int main()
{
    int n,i;
    cin>>n;
    fo(i,n-1)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    Fo(i,1,n+1)
        cin>>val[i];
    dfs(1,0);
    cout<<dp[1][0];
}
