#include<bits/stdc++.h>
using namespace std;
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
const int N=3e5;
vi g[N];
vector<int>w(N);
long long subtsize[N];
long long dp[N][201];
vector<int>a;
void dfs(int u, int par)
{
    int siz=0;
    int sum=0;
    for(int child:g[u])
    {
        if(child==par)
            continue;
        dfs(child,u);
        sum+=dp[child][0];
        siz+=subtsize[child];
    }
    a.pb(u);
    dp[u][0]=w[u]+sum;
    subtsize[u]=1+siz;
}
int main()
{
    int n,k,u,v;
    cin>>n>>k;
    Fo(i,1,n+1)
        cin>>w[i];
    fo(i,n-1)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1,0);
    for(int i=1;i<=n;i++)
        cout<<dp[i][0]<<" ";
}


