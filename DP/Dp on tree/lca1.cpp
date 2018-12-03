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
const int LG = 20;
//LCA begins
//1 based index
int a[N], lvl[N], P[N][LG];
void dfs(int u, int par){
    //calculate level for each node
    lvl[u] = 1+lvl[par];
    P[u][0] = par;
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

int lca(int u, int v){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);
    //find maximum power of 2 which is less than or equal to lvl[u]
    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;
    //iterate from greater value of lg to 0 and move upwards towards v
    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])  //after making transition of 2 raise to power i steps if I am greater than lvl[v] the move to parent of p[u][i]
            u = P[u][i];
    }
    //at the end of above for loop it ensure that u and v are at same level
    if (u == v)
    	return u;
    //move both u and v and same speed
    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }

    return P[u][0];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, n, q, m, j;
	int u, v;
	cin >> n;
	fo(i, n-1){
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
	}

	fo(i, LG) fo(j, n+1) P[j][i] = -1;
	lvl[0] = -1;

	dfs(1, 0);

	for(i=1; i<LG; i++){
        Fo(j, 1, n+1)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
	}
	cin>>u>>v;
	cout<<lca(u,v);

	return 0;
}
