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
const int N = 2e5;
vi g[N];
int c[N];
//The number of ways such that the subtree that is rooted at u has no black nodes at all,
//while the remaining subtrees formed have exactly one black node each.dp[u][0]
// the number of ways such that the subtree that is rooted at u has exactly one black nodes,
//and the remaining subtrees formed have also exactly one black node each. dp[u][1]
ll dp[N][2];
void dfs(int u, int par)
{
    dp[u][0]=1-c[u];
    dp[u][1]=c[u];
    ll zero,one;
    for(int v:g[u]){
        if(v==par) continue;
    zero= dp[u][0];
    one= dp[u][1];
    //initialize 0 for adding
    dp[u][0]=0;
    dp[u][1]=0;
    //not including v as children of subtree rooted as u
    dp[u][0]=zero*dp[v][1];
    dp[u][0]%=mod;
    dp[u][1]=one*dp[v][1];
    dp[u][1]%=mod;
    //including v as child of subtree rooted as u
    dp[u][0]+=zero*dp[v][0];
    dp[u][0]%=mod;
    dp[u][1]+=one*dp[v][0]+zero*dp[v][1];
    dp[u][1]%=mod;
    }


}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int u;
        cin>>u;
        g[u].pb(i+1);
        g[i+1].pb(u);
    }
    int i;
    fo(i,n)
        cin>>c[i];
    dfs(0,-1);
    cout<<dp[0][1]<<endl;
}
